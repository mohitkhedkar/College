package com.rey.secureApp;

import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.RequestMapping;
@CrossOrigin
@Controller
public class MvcController {

	@RequestMapping("/file")
	public String get()//Model m)
	{
//		m.addAttribute("file","src/main/resources/static/doc1.png");
		return "home";
	}
}
