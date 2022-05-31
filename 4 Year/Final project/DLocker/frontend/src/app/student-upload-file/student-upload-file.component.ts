import { HttpClient, HttpEventType, HttpHeaders, HttpResponse } from '@angular/common/http';
import { Component, OnInit } from '@angular/core';
import { ActivatedRoute, Router } from '@angular/router';
import { Data } from '../data';
import { Files } from '../files';
import { JwtToken } from '../jwt-token';

@Component({
  selector: 'app-student-upload-file',
  templateUrl: './student-upload-file.component.html',
  styleUrls: ['./student-upload-file.component.css']
})
export class StudentUploadFileComponent implements OnInit {
    file!: File;
    fileName:string="SSC";
    static fileN:string="";
    flag:boolean=true;
    url:any;
    filesArr:Data[]=[];
  constructor(private http:HttpClient, private router:Router){

    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
   console.log(JwtToken.username +"us");
    http.post("http://localhost:8080/student/getFiles/"+JwtToken.username,"",{headers:headers}).subscribe((data:any)=>{
      this.filesArr=Object.values(data) ;
    });
  }
  ngOnInit(): void {
  }
event:any;
  submit(event:any){
    var t='Bearer '+JwtToken.jwt;
    let headers = new HttpHeaders().set("Authorization", t);
    // headers.set('Content-Type', 'multipart/form-data');
    const data=new FormData();
    // fileName:string=JwtToken.username+"/file";
    // data.set('file)
    this.event=event;
    console.log(this.file)

    this.file=event.target.files[0];
    if(this.file.size>2097152)
      window.alert("File size too large");
     else{ 
       var allowedExtensions = /(\.jpg|\.jpeg|\.png)$/i;
       if(!allowedExtensions.exec(this.file.name))
        window.alert("Only .jpg,.jpeg,.png extensions allowed");
        else
        {
         let exten:string=this.file.name.substring(this.file.name.indexOf('.'))
        
        StudentUploadFileComponent.fileN=this.fileName+exten;
        console.log(this.file)
        this.flag=true;
        data.append('imageFile',this.file,JwtToken.username+'\\'+ this.fileName+exten);
        console.log("hi")
   
    this.http.post("http://localhost:8080/student/byImageFile",data,{headers:headers, observe:'response', responseType:'text'}).subscribe((data:any)=>{
      // console.log("hi")
      // console.log(data);
      // this.filesArr=Object.values(data) ;
    });
    this.http.post("http://localhost:8080/student/getFiles/"+JwtToken.username,"",{headers:headers}).subscribe((data:any)=>{
    console.log(JwtToken.username+"name");  
    this.filesArr=data;
      console.log(data);
    });
  }}

  }
     
  //  image : any;   
  // private readonly imageType : string = 'data:image/PNG;base64,'; 
  //  imageString!:string;
// imageFile!:Blob;
getFile()
{
  var t='Bearer '+JwtToken.jwt;
  let headers = new HttpHeaders().set("Authorization", t);
  this.http.post("http://localhost:8080/student/files/"+JwtToken.username+"/"+this.fileName,"",{headers:headers}).subscribe((data:any)=>{
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
});}}










//     let imageBase64String= btoa(data);
// this.imageString='data:image/PNG;base64, '+imageBase64String;
//     console.log(data);

  // var reader = new FileReader();
  // reader.readAsDataURL(this.imageFile);//this.event.target.files[0]);
  
  // reader.onload = (_event) => {
  //   // this.msg = "";
  //   this.url = reader.result; 
  
  // this.router.navigate(['/student/retrieveFile']);





















// selectedFile= null;
  // file!: File;
  // currentFileUpload: any ;
  // progress: { percentage: number } = { percentage: 0 };
  // selectedFiles!: FileList;
  // changeImage = false;
 
//   handleFileInput(files: FileList) {
//     this.fileToUpload = files.item(0);
// }
// uploadFileToActivity() {
//   this.fileUploadService.postFile(this.fileToUpload).subscribe(data => {
//     // do something, if upload success
//     }, error => {
//       console.log(error);
//     });
// }
  // downloadFile(){
  //   const link = document.createElement('a');
  //   link.setAttribute('target', '_blank');
  //   link.setAttribute('href', '_File_Saved_Path');
  //   link.setAttribute('download', 'file_name.pdf');
  //   document.body.appendChild(link);
  //   link.click();
  //   link.remove();
  // }
  // change($event:any) {
  //   this.changeImage = true;
  // }
  // changedImage(event:any) {
  //   this.selectedFile = event.target.files[0];
  // }
  // upload() {
  //   this.progress.percentage = 0;
  //   this.currentFileUpload = this.selectedFiles.item(0);
//this.pushFileToStorage().subscribe((event: { type: any; loaded: number; total: number; }) => 
//{
    //   if (event.type === HttpEventType.UploadProgress) {
    //     this.progress.percentage = Math.round(100 * event.loaded / event.total);
    //   } else if (event instanceof HttpResponse) {
    //      alert('File Successfully Uploaded');
    //   }
      
    //  }
    // );
  

  // pushFileToStorage(){}
  // selectFile(event:any) {
  //   this.selectedFiles = event.target.files;
  // }

  // ngOnInit(): void {
  // }
  // submit()
  // {
  //   let obj:any={
  //     "file":this.file
  //   }
 

