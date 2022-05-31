import { Component, OnInit } from '@angular/core';
import { User } from '../user';
import { HttpClient, HttpResponse ,HttpHeaders} from '@angular/common/http';
import { ActivatedRoute, Params } from '@angular/router';
import { JwtToken } from '../jwt-token';

@Component({
  selector: 'app-admin-change-role',
  templateUrl: './admin-change-role.component.html',
  styleUrls: ['./admin-change-role.component.css']
})

    
export class AdminChangeRoleComponent implements OnInit {
users:User[]=[];
data:string="";
disable:boolean=false;
 
  constructor(private http:HttpClient, private route: ActivatedRoute) {
    // const j=new JwtToken();
    //`eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzI1NiJ9.eyJpc3MiOiJodHRwOlwvXC9sb2NhbGhvc3Q6ODAwMFwvYXBpXC9sb2dpbiIsImlhdCI6MTUzNzcxNTMyNSwiZXhwIjoxNTM3NzE4OTI1LCJuYmYiOjE1Mzc3MTUzMjUsImp0aSI6IlBKWVhnSkVyblQ0WjdLTDAiLCJzdWIiOjYsInBydiI6Ijg3ZTBhZjFlZjlmZDE1ODEyZmRlYzk3MTUzYTE0ZTBiMDQ3NTQ2YWEifQ.1vz5lwPlg6orzkBJijsbBNZrnFnUedsGJUs7BUs0tmM`;

  //   var headers_object = new HttpHeaders();
  //       headers_object.set('Content-Type', 'application/json');
  //       headers_object.set("Authorization", "Bearer " + t);//append("Authorization", "Bearer " + t);

  //       const httpOptions = {
  //         headers: headers_object
  //       };


  // //  this.http.post(
  // //                 'http://localhost:8000/api/role/Post', {limit:10}, httpOptions
  // //                ).subscribe(resp => {
  // //                 this.roles = console.log(resp)
  // //                 }
  // //               );
 // let headers = new HttpHeaders();
  // headers = headers.set('')
  // headers.set('Content-Type', 'application/json');
  var t='Bearer '+JwtToken.jwt;
  let headers = new HttpHeaders().set("Authorization", t);
  http.post("http://localhost:8080/admin/getUsers","",{headers:headers}).subscribe((data:any)=>{
      this.users=data;
    });
   } 

   ngOnInit():void{
    // this.route.queryParams.subscribe((queryParams: Params) => {
    //   this.data= queryParams['data'];
    // });
  }


   update(username:string,role:string)
   {
     this.disable=true;
      let obj:any=
       {
        "username":username,
        "role":role
       }
       var t='Bearer '+JwtToken.jwt;
       let headers = new HttpHeaders().set("Authorization", t);
      //  headers.set('Content-Type', 'application/json');

       this.http.post("http://localhost:8080/admin/changeRole",obj,{headers:headers}).subscribe((data:any)=>{
           this.users=data;
           this.disable=false;
         });
      } 
   }
  
