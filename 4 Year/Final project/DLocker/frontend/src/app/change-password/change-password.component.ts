import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';

@Component({
  selector: 'app-change-password',
  templateUrl: './change-password.component.html',
  styleUrls: ['./change-password.component.css']
})
export class ChangePasswordComponent implements OnInit {

  data:string="";
  password:string="";
  otp:number=0;
  email:string="";
  
  constructor(private http:HttpClient) { }

  
  updatePassword()
  {
    let obj:any={
      "email":this.email,
      "password":this.password,
      "otp":this.otp
    }
    this.http.post("http://localhost:8080/updatePassword",obj,{responseType:'text'}).subscribe((data:any)=>
    {
      if(data=="Otp expired")
        window.alert("Otp expired")
      else
        this.data="Password Updated"  
    });
  }

  ngOnInit(): void {
  }

}
