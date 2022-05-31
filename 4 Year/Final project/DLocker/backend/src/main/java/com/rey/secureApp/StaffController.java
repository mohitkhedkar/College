package com.rey.secureApp;

import java.io.File;
import java.io.IOException;
import java.nio.file.Files;
import java.util.Base64;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.PostMapping;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.rey.secureApp.dao.DataRepository;
import com.rey.secureApp.dao.UserRepository;
import com.rey.secureApp.encrypt.FilesToSend;
import com.rey.secureApp.entity.Data;
import com.rey.secureApp.entity.User;

@CrossOrigin
@RestController
@RequestMapping("/staff")
public class StaffController {
	
	@Autowired DataRepository datarepo;
	
	@Autowired
	UserRepository userRepo;
	@RequestMapping("/greet")
	public String hello()
	{
		return "Hello staff";
	}
	
	@RequestMapping("/getAll")
	public List<Data> getAll()
	{
		return datarepo.findAll();
	}
	
	@RequestMapping("/getVerified")
	public List<Data> getVerified()
	{
		return datarepo.findByStatus(true);
	}
	
	@RequestMapping("/getNonVerified")
	public List<Data> getNonVerified()
	{
		return datarepo.findByStatus(false);
	}
	
	@RequestMapping("/getByUsername/{username}")
	public List<Data> getByUsername(@PathVariable String username)
	{
		List<Data> data=datarepo.findByUsername(username);
		return data;
	}
	
	@RequestMapping("/changeStatus/{username}/{filename}/{status}")
	public void changeStatus( @PathVariable String filename, @PathVariable String username, @PathVariable boolean status)
	{
		Data data =datarepo.findByLink("http://localhost:4200/shareFile/"+username+"/"+filename);
		data.setStatus(status);
		datarepo.save(data);
		
	}
	@PostMapping(value="/files/{username}/{filename}")//,produces = MediaType.I)
	  public FilesToSend getFile(@PathVariable String username,@PathVariable String filename) {
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
FilesToSend files=null;
	 String encodeImage="";
	try {
		encodeImage = Base64.getEncoder().withoutPadding().encodeToString(Files.readAllBytes(file.toPath()));
//	System.out.println(encodeImage);
//	  jsonMap.put("content", encodeImage); 
		files=new FilesToSend(fileType,encodeImage);
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} 
	  return files; 
	}
}
