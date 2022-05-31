import { HttpClient, HttpHeaders } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { Data } from '../data';
import { JwtToken } from '../jwt-token';

@Component({
  selector: 'app-staff',
  templateUrl: './staff.component.html',
  styleUrls: ['./staff.component.css']
})
export class StaffComponent implements OnInit {
username:string="";
url:any;
filesArr:any=[];
  constructor(private http: HttpClient) { }

  ngOnInit(): void {
  }

  getFiles(fileName:string, username:string){ var t='Bearer '+JwtToken.jwt;
  let headers = new HttpHeaders().set("Authorization", t);
  this.http.post("http://localhost:8080/staff/files/"+username+"/"+fileName,"",{headers:headers}).subscribe((data:any)=>{
   if(data!=null){
    const byteCharacters = atob(data.base64);
const byteNumbers = new Array(byteCharacters.length);
for (let i = 0; i < byteCharacters.length; i++) {
  byteNumbers[i] = byteCharacters.charCodeAt(i);
}
const byteArray = new Uint8Array(byteNumbers);
const blob = new Blob([byteArray], {type: data.type });//'image/png'
 var reader = new FileReader();
  reader.readAsDataURL(blob);//this.event.target.files[0]);
  
  reader.onload = (_event) => {
    // this.msg = "";
    this.url = reader.result; 
}}
else
 window.alert("File not uploaded");
});}
  closeFile(){
    this.url=null;
  }
  getAll(){
    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
    this.http.post("http://localhost:8080/staff/getAll","",{headers:headers}).subscribe((data)=>{
      this.filesArr=data;
    });
  }

  getVerified(){
    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
    this.http.post("http://localhost:8080/staff/getVerified","",{headers:headers}).subscribe((data)=>{
      this.filesArr=data;
    });
  }

  getNonVerified(){
    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
    this.http.post("http://localhost:8080/staff/getNonVerified","",{headers:headers}).subscribe((data)=>{
      this.filesArr=data;
    });
  }

  getByUsername(){
    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
    this.http.post("http://localhost:8080/staff/getByUsername/"+this.username,"",{headers:headers}).subscribe((data)=>{
      this.filesArr=data;
    });
    this.username="";
  }

  updateStatus(status:boolean, filename:string, username:string)
  {
    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
    this.http.post("http://localhost:8080/staff/changeStatus/"+username+"/"+filename+"/"+status,"",{headers:headers}).subscribe(()=>{
    });
  }

}
