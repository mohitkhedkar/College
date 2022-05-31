import { Component, OnInit } from '@angular/core';
import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Router } from '@angular/router';
import { JwtToken } from '../jwt-token';

@Component({
  selector: 'app-login',
  templateUrl: './login.component.html',
  styleUrls: ['./login.component.css']
})
export class LoginComponent implements OnInit {

  constructor(private http:HttpClient, private router : Router) { }
  username:string="";
  password:string="";
  data:string="";
  email:string="";
  disable:boolean=false;
  isShown:boolean=false;
  otp:number=0;

  

  ngOnInit(): void {
  }
  login()
  {
    let obj:any=
    {
      "username":this.username,
      "password":this.password
    }
    this.http.post("http://localhost:8080/authenticate",obj).subscribe((data:any)=>{
      console.log(data);
     if(data.error=="Account blocked" || data.error=="Verify your email" || data.error=="Incorrect username or password")
      {
        this.data=data.error;
      }
    else
      {
        JwtToken.jwt=data.jwt;
        // const j=new JwtToken(data.jwt);
        // j.setJwt(data.jwt);
        if(data.role=="ROLE_stu")
        { 
          console.log("username " +this.username);
          JwtToken.username=this.username;
          this.router.navigate(['/student']); 
        }
        else if(data.role=="ROLE_staff")
        {
          this.router.navigate(['/staff']);
        }
        else
        {
          this.router.navigate(['/admin']);
        }
      }
     });
  }
  forgetPassword()
  {
    this.disable=true;
    let obj:any={
      "email":this.email
    }
    this.http.post("http://localhost:8080/changePassword",obj,{ responseType:'text'}).subscribe((data:any)=>{
      if(data=="sentMail")
      {
        this.disable=false;
        this.isShown=true;
        // this.router.navigate(['changePassword']);
      }
      else
      {
        window.alert("Something went wrong");
      } 
    });
  }

  
}


