import { Component, OnInit } from '@angular/core';
import { HttpClient } from '@angular/common/http';


@Component({
  selector: 'app-register',
  templateUrl: './register.component.html',
  styleUrls: ['./register.component.css']
})
export class RegisterComponent implements OnInit {
  username:string="";
  password:string="";
  email:string="";
  data:string="";
  constructor(private http:HttpClient) { }

  ngOnInit(): void {
  }

  register()
  {
    let obj:any={
      "email":this.email,
      "username":this.username,
      "password":this.password
    }
    this.http.post("http://localhost:8080/register",obj,{responseType:"text"}).subscribe((data:any)=>{
      if(data=="Registered")
        {
          this.data="Registered, please verify your email";
        }
      else
        this.data=data;  
    });
  }
 
}
