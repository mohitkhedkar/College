import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';

import { AppRoutingModule } from './app-routing.module';
import { AppComponent } from './app.component';
import { StudentComponent } from './student/student.component';
import { RegisterComponent } from './register/register.component';
import { LoginComponent } from './login/login.component';
import { Routes, RouterModule } from '@angular/router';
import { FormsModule } from '@angular/forms';
import {HttpClientModule} from '@angular/common/http';
import { ChangePasswordComponent } from './change-password/change-password.component';
import { VerifyEmailComponent } from './verify-email/verify-email.component';
import { AdminComponent } from './admin/admin.component';
import { StaffComponent } from './staff/staff.component';
import { AdminChangeRoleComponent } from './admin-change-role/admin-change-role.component';
import { AdminDeleteUserComponent } from './admin-delete-user/admin-delete-user.component';
import { JwtToken } from './jwt-token';
import { StudentUploadFileComponent } from './student-upload-file/student-upload-file.component';
import { StudentRetrieveFileComponent } from './student-retrieve-file/student-retrieve-file.component';
import { StudentShareFileComponent } from './student-share-file/student-share-file.component';

const appRoutes: Routes = [
  {path: '', component: LoginComponent ,children:[{path:'changePassword', component:ChangePasswordComponent}]},
  {path:'register', component:RegisterComponent, children:[{path:'verifyEmail',component:VerifyEmailComponent}] },
  {path:'student',component:StudentComponent, children:[{path:'uploadFile',component:StudentUploadFileComponent},
                                                        {path:'retrieveFile', component:StudentRetrieveFileComponent}]},
  {path:'staff', component:StaffComponent},
  {path:'admin', component:AdminComponent, children: [{path:'changeRole', component:AdminChangeRoleComponent}, 
                                                      {path:'deleteUser', component:AdminDeleteUserComponent}]},
  {path:'shareFile/:name/:file', component:StudentShareFileComponent}]
 

@NgModule({
  declarations: [
    AppComponent,
    StudentComponent,
    RegisterComponent,
    LoginComponent,
    ChangePasswordComponent,
    VerifyEmailComponent,
    AdminComponent,
    StaffComponent,
    AdminChangeRoleComponent,
    AdminDeleteUserComponent,
    StudentUploadFileComponent,
    StudentRetrieveFileComponent,
    StudentShareFileComponent
  ],
  imports: [
    BrowserModule,
    FormsModule,
    HttpClientModule,
    AppRoutingModule,RouterModule.forRoot(appRoutes)
  ],
  providers: [],
  bootstrap: [AppComponent]
})

export class AppModule {
  
 }
