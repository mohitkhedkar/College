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
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestPart;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.multipart.MultipartFile;

import com.rey.secureApp.dao.DataRepository;
import com.rey.secureApp.dao.UserRepository;
import com.rey.secureApp.encrypt.FilesToSend;
import com.rey.secureApp.entity.Data;
import com.rey.secureApp.entity.User;
//@PreAuthorize("hasRole('stu')")
@CrossOrigin   
@RequestMapping("/student")
@RestController
public class StudentController {

	@Autowired 
	DataRepository dRepo;
	
	@Autowired
	UserRepository uRepo;
	@RequestMapping("/greet")
	public String hello()
	{
		return "Hello student";
	}
	
	
	@PostMapping( value = "/byImageFile")//, consumes = { "multipart/form-data" })  
	public boolean postMap( @RequestPart("imageFile") MultipartFile imageFile)//)//,   
		//	@RequestPart ( "fieldsToExtract") RequestDto requestDto )
	{
		String fileName=imageFile.getOriginalFilename();
		File f=new File("D:\\Users\\shrey\\Documents\\sts\\secureApp2\\src\\main\\resources\\static\\"+fileName);
		long userid=0;
		try {
			
			f.createNewFile();
//			 f=file.getFile();
			imageFile.transferTo(f);
			String username=fileName.substring(0, fileName.indexOf('\\'));
			String filename=fileName.substring( fileName.indexOf('\\')+1,fileName.indexOf('.'));
//			User user=uRepo.findByUsername(fileName.substring(0, fileName.indexOf('\\')));
//			System.out.println(user);
//			userid=user.getId();
			String link="http://localhost:4200/shareFile/"+username+"/"+filename;
			Data d = new Data(filename,username,link);
			Data d1=dRepo.findByLink(link);
			if(d1==null)
				dRepo.save(d);
//	            CryptoUtils.encrypt("Mary hasertwyetr", f, f1);
//	            f.delete();
}
//	            CryptoUtils.decrypt(key, encryptedFile, decryptedFile);
//	        } catch (CryptoException ex) {
//	            System.out.println(ex.getMessage());
//	            ex.printStackTrace();
//	        }
			catch (IllegalStateException   | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
			}
		return true;
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
	  FilesToSend files=null;
	 String encodeImage="";
	try {
		encodeImage = Base64.getEncoder().withoutPadding().encodeToString(Files.readAllBytes(file.toPath()));
	files=new FilesToSend(fileType,encodeImage);
	} catch (IOException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
	} 
	  return files; 
	}
	
	
	@PostMapping("getFiles/{userName}")
	public List<Data> getFiles(@PathVariable String userName)
	{
		
//		User user=uRepo.findByUsername(userName);
		System.out.println(userName+2);
		List<Data> data=dRepo.findByUsername(userName);
		System.out.println(data +"aaa");
		return data;
	}
	
	
	
	
	
	
	
	
	
	
	
	
	
	
//		FileInputStream fis=new FileInputStream(file);
//	
//	    file.canRead();
//	   
//			 inputImage = ImageIO.read(fis);
//		} catch (FileNotFoundException e1) {
//			// TODO Auto-generated catch block
//			e1.printStackTrace();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//	    return true; 
//	   System.out.println(file.exists());
//	    try {
//			file.createNewFile();
//		} catch (IOException e) {
//			// TODO Auto-generated catch block
//			e.printStackTrace();
//		}
//	    InputStream in = getClass()
//	    	      .getResourceAsStream("D:\\Users\\shrey\\Documents\\sts\\JwtApp\\src\\main\\resources\\static\\"+filename+".png");
//	    	    return IOUtils.toByteArray(in);
//	    return ResponseEntity.ok()//.contentType(MediaType.parseMediaType())   
//	        .h//.header(HttpHeaders.CONTENT_TYPE, MediaType.MULTIPART_MIXED).body(file); //.CONTENT_DISPOSITION, "attachment; filename=\"" + filename + "\"").body(file);
//	    return ResponseEntity.ok().contentType(MediaType.IMAGE_PNG).body(file);//.body(file);
//	    return file;  
//	}
//	@GetMapping("/files")
//	  public ResponseEntity<List<FileInfo>> getListFiles() {
//	      String filename = path.getFileName().toString();
//	      String url = MvcUriComponentsBuilder
//	          .fromMethodName(StudentController.class, "getFile", path.getFileName().toString()).build().toString();
//
//	      return new FileInfo(filename, url);
//	    }).collect(Collectors.toList());
//
//	    return ResponseEntity.status(HttpStatus.OK).body(fileInfos);
//	  	
	
//	@GetMapping("/files1/{filename}")
//	  public ResponseEntity<FileInfo> getListFiles(@PathVariable String filename) {
//	    FileInfo fileInfos = ((Object) new File("D:\\Users\\shrey\\Documents\\sts\\JwtApp\\src\\main\\resources\\static\\"+filename)).map(path -> {
//	      String filename = path.getFileName().toString();
//	      String url = MvcUriComponentsBuilder
//	          .fromMethodName(FilesController.class, "getFile", path.getFileName().toString()).build().toString();
//
//	      return new FileInfo(filename, url);
//	    }).collect(Collectors.toList());
//
//	    return ResponseEntity.status(HttpStatus.OK).body(fileInfos);
//	  }

}
