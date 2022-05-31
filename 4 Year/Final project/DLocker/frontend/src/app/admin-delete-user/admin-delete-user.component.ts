import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { JwtToken } from '../jwt-token';
import { User } from '../user';

@Component({
  selector: 'app-admin-delete-user',
  templateUrl: './admin-delete-user.component.html',
  styleUrls: ['./admin-delete-user.component.css']
})
export class AdminDeleteUserComponent implements OnInit {
  users:User[]=[];
  disable:boolean=false;
  constructor(private http: HttpClient) {
    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
    http.post("http://localhost:8080/admin/getUsers","",{headers:headers}).subscribe((data:any)=>{
        this.users=data;
      });
   }

  ngOnInit(): void {
  }

  update(username:string, status:boolean)
  {
    this.disable=true;
    let obj:any=
     {
      "username":username,
      "status":status
     }
     var t='Bearer '+JwtToken.jwt;
     let headers = new HttpHeaders().set("Authorization", t);
    //  headers.set('Content-Type', 'application/json');

     this.http.post("http://localhost:8080/admin/changeStatus",obj,{headers:headers}).subscribe((data:any)=>{
         this.users=data;
         this.disable=false;
       });
    } 
  }

