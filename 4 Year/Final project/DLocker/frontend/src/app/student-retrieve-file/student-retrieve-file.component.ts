import { Component, OnInit } from '@angular/core';
import { StudentUploadFileComponent } from '../student-upload-file/student-upload-file.component';

@Component({
  selector: 'app-student-retrieve-file',
  templateUrl: './student-retrieve-file.component.html',
  styleUrls: ['./student-retrieve-file.component.css']
})
export class StudentRetrieveFileComponent implements OnInit {

  constructor() { 
    this.file=StudentUploadFileComponent.fileN;

  }
  file:any;
  ngOnInit(): void {
  }

}
