import { HttpClient } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';

@Component({
  selector: 'app-student-share-file',
  templateUrl: './student-share-file.component.html',
  styleUrls: ['./student-share-file.component.css']
})
export class StudentShareFileComponent implements OnInit {
username:string="";
filename:string="";
url:any;
  constructor(private route:ActivatedRoute, private http:HttpClient) 
  {
    this.username= this.route.snapshot.params['name'],    
    this.filename= this.route.snapshot.params['file']
   let fileName=this.username+'\\'+this.filename
      this.http.post("http://localhost:8080/sharefiles/"+this.username+"/"+this.filename,"").subscribe((data:any)=>{
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
     window.alert("Something went wrong");
    });}
   

  ngOnInit(): void {
  }

}
