package com.rey.secureApp;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.time.Duration;
import java.time.LocalDateTime;
import java.util.Base64;
import java.util.List;
import java.util.Random;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.mail.SimpleMailMessage;
import org.springframework.mail.javamail.JavaMailSender;
import org.springframework.security.authentication.BadCredentialsException;
import org.springframework.security.core.userdetails.UserDetails;
import org.springframework.security.crypto.bcrypt.BCrypt;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.RestController;

import com.rey.secureApp.dao.DataRepository;
import com.rey.secureApp.dao.UserRepository;
import com.rey.secureApp.encrypt.FilesToSend;
import com.rey.secureApp.entity.Data;
import com.rey.secureApp.entity.User;
import com.rey.secureApp.jwt.AuthenticationRequest;
import com.rey.secureApp.jwt.JwtUtil;
import com.rey.secureApp.jwt.Token;
import com.rey.secureApp.security.MyUserDetailsService;
//Access only to localhost, strong pass, limit access to few hosts, change port and do not use root 
//@PreAuthorize("hasRole('user')")

 @RestController
 @CrossOrigin
public class Controller {
//	@Autowired
//	private AuthenticationManager authenticationManager;

	@Autowired
	private MyUserDetailsService userDetailsService;
  
	@Autowired
	private JwtUtil jwtTokenUtil;

	@Autowired
	private JavaMailSender javaMailSender;
	
	@Autowired
	private UserRepository repo;
	
	@Autowired
	private DataRepository dRepo;
	
	@RequestMapping("/")
	public String home()
	{
		return "Hello";	
	}

	@RequestMapping("/register")
	public String register(@RequestBody User us)
	{
		List<User> user= repo.findByEmail(us.getEmail());
		User uname=repo.findByUsername(us.getUsername());
		if(user.size()==0 && uname==null)
		{
			us.setPassword(BCrypt.hashpw(us.getPassword(), BCrypt.gensalt()));
			
			User u=new User( us.getUsername(), us.getPassword(), us.getEmail());
			repo.save(u);
			File f=new File("D:\\Users\\shrey\\Documents\\sts\\secureApp2\\src\\main\\resources\\static\\"+us.getUsername());
			boolean bool= f.mkdir();
			if(bool)
				System.out.println("created");
			Random random=new Random();
			random.ints(0, 9);
			int otp=0;
			for (int i = 0; i < 6; i++)
				otp=otp*10+random.nextInt(9);
			System.out.println(otp);
			repo.setOtp(otp, u.getEmail());
			SimpleMailMessage msg = new SimpleMailMessage();
	        msg.setTo(u.getEmail());
	        msg.setSubject("Verify your email");
	        msg.setText("Otp:"+otp);
	        javaMailSender.send(msg);	
			return"Registered";
		}
		else if(user.size()>1)	
			return "email already used";
		else
			return "username already used";
	}
//	@RequestMapping("/mailAuthenticate")
//	public String sendMail( @RequestBody User u)
//	{
//		Random random=new Random();
//		random.ints(0, 9);
//		int otp=0;
//		for (int i = 0; i < 6; i++)
//			otp=otp*10+random.nextInt(9);
//		repo.setOtp(otp, u.getEmail());
//		SimpleMailMessage msg = new SimpleMailMessage();
//        msg.setTo(u.getEmail());
//        msg.setSubject("Verify your email");
//        msg.setText("Otp:"+otp);
//        javaMailSender.send(msg);
//		return "sentMail";
//	}
	
	@RequestMapping("/otpVerify")
	public String otpVerify(@RequestBody User u)
	{
		
		List<User> us= repo.findByEmail(u.getEmail());
		System.out.println(us);
		if(us.size()==0)
			return "Invalid Email";
		if(u.getOtp()==us.get(0).getOtp())
		{
			repo.setAuthentication(u.getEmail());
			return "Email verified";
		}
		return "Wrong otp";
	}
	
	@RequestMapping(value="/changePassword", method = RequestMethod.POST)
	public Object changePassword(@RequestBody User u)
	{
		Random random=new Random();
		random.ints(0, 9);
		int otp=0;
		for (int i = 0; i < 6; i++)
			otp=otp*10+random.nextInt(9);
		System.out.println("email");
//		SimpleDateFormat formatter= new SimpleDateFormat("YYYY-MM-DD hh:mm:ss");
		LocalDateTime n=LocalDateTime.now();
		boolean status=repo.setExpiry(u.getEmail(), otp, n);
		if(status)
		{
			SimpleMailMessage msg = new SimpleMailMessage();
	        msg.setTo(u.getEmail());
	        msg.setSubject("Request for password change");
	        msg.setText("Otp:"+otp+"\n Otp is valid only for an hour");
	        javaMailSender.send(msg);
	        System.out.println("sent");
			return "sentMail";
		}
		return "Something went wrong";
		
	}
	@RequestMapping("/updatePassword")
	public String updatePassword(@RequestBody User us)
	{
		List<User> user= repo.findByEmail(us.getEmail());
		LocalDateTime n=LocalDateTime.now();
		LocalDateTime m=user.get(0).getExpiry();
		Duration duration = Duration.between(m, n);
		if(duration.getSeconds()>3600)
			return "Otp expired";
		us.setPassword(BCrypt.hashpw(us.getPassword(), BCrypt.gensalt()));
		repo.setPassword(us.getEmail(),us.getPassword());
		return "password updated"; 
	}
	//ResponseEntity<?>
	@RequestMapping(value="/authenticate", method = RequestMethod.POST)
	public Token  createAuthenticationToken(@RequestBody AuthenticationRequest authenticationRequest) throws  Exception{
		String error = null;
		try 
		{
			User user=repo.findByUsername(authenticationRequest.getUsername());
			if(user==null || !BCrypt.checkpw(authenticationRequest.getPassword(), user.getPassword()))
				{
					error="Incorrect username or password";
					throw new BadCredentialsException("Incorrect username or password");
				}
//			authenticationManager.authenticate(new UsernamePasswordAuthenticationToken(
//					authenticationRequest.getUsername(), authenticationRequest.getPassword()));
		}catch (BadCredentialsException e) {
			error="Incorrect username or password";
			throw new Exception("Incorrect username or password");
		}
		final UserDetails userDetails=userDetailsService
				.loadUserByUsername(authenticationRequest.getUsername());
		User us=repo.findByUsername(authenticationRequest.getUsername());
		if(!us.getStatus())
			error="Account blocked";//(ResponseEntity<?>) ResponseEntity.ok("Account blocked");
		if(us.getAuthentication()==0)
			error="Verify your email";//return (ResponseEntity<?>) ResponseEntity.ok("Verify your email");
		String jwt="";
		if(error==null)
			jwt = jwtTokenUtil.generateToken(userDetails);
		
		
		return new Token(error,jwt,us.getRole());
	}
	
	@PostMapping(value="/sharefiles/{username}/{filename}")//,produces = MediaType.I)
	  public FilesToSend getFile(@PathVariable String username,@PathVariable String filename) {
		FilesToSend files=null;
		Data d= dRepo.findByLink("http://localhost:4200/shareFile/"+username+"/"+filename);
		if(d.isStatus()) {
		String fileType="image/jpg";
	    File  file = new File("D:\\Users\\shrey\\Documents\\sts\\secureApp2\\src\\main\\resources\\static\\"+username+"\\"+filename+".jpg");
	  if(!file.exists())
	  {
	    file = new File("D:\\Users\\shrey\\Documents\\sts\\secureApp2\\src\\main\\resources\\static\\"+username+"\\"+filename+".png");
	    fileType="image/png";
	  }
	  if(!file.exists())
	  {
		  file = new File("D:\\Users\\shrey\\Documents\\sts\\secureApp2\\src\\main\\resources\\static\\"+username+"\\"+filename+".jpeg");
		  fileType="image/jpeg";  
	  }
	  System.out.println(file.exists());
//BufferedImage inputImage = null;
	
//Map<String, String> jsonMap = new HashMap<>(); 
	 String encodeImage="";
	try {
		encodeImage = Base64.getEncoder().withoutPadding().encodeToString(Files.readAllBytes(file.toPath()));
//	System.out.println(encodeImage);
//	  jsonMap.put("content", encodeImage); 
		files=new FilesToSend(fileType,encodeImage);
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} }
	  return files; 
	}
	
	
	
}
