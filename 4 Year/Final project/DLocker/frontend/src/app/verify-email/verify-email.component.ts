import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { Router } from '@angular/router';

@Component({
  selector: 'app-verify-email',
  templateUrl: './verify-email.component.html',
  styleUrls: ['./verify-email.component.css']
})
export class VerifyEmailComponent implements OnInit {
  data:string="";
  email:string="";
  otp:number=0;
  isShown:boolean=false;
  constructor(private http:HttpClient, private router:Router) { }

  ngOnInit(): void {
  }

  verifyEmail()
  {
    console.log("verify")
    let obj:any={
      "email":this.email,
      "otp":this.otp
    }
    this.http.post("http://localhost:8080/otpVerify", obj, {responseType:"text"}).subscribe((data:any)=>{
      console.log(data);
      this.data=data;
      if(data=="Email verified")
        this.isShown=true;
    });
  }

}
