package com.rey.secureApp;

import java.util.ArrayList;
import java.util.List;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestBody;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import com.rey.secureApp.dao.UserRepository;
import com.rey.secureApp.entity.User;

@CrossOrigin
@RestController
@RequestMapping("/admin")
public class AdminController {

	@Autowired
	UserRepository repo;
	
	@RequestMapping("/getUsers")
	public List<User> getUsers()
	{
		try
		{
			return repo.findAll();
		}catch(Exception e)
		{
			e.printStackTrace();
		}
		return new ArrayList<User>();
	}
	
	@RequestMapping("/changeRole")
	public List<User> changeRole(@RequestBody User user)
	{
		System.out.println("Change role");
		repo.setRole(user.getUsername(),user.getRole());
		return repo.findAll();
	}
	
	@RequestMapping("/changeStatus")
	public List<User> deleteUser(@RequestBody User user)
	{
			repo.setStatus(user.getUsername(), user.getStatus());
			return repo.findAll();
	}
	
//	@RequestMapping("/unBlockUser")
//	public String unBlock(@RequestBody User user)
//	{
//		repo.setStatus(user.getUsername(), true);
//		return "Account unblocked";
//	}
}
