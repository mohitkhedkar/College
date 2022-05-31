import { Injectable } from '@angular/core';

@Injectable({
  providedIn: 'root',
})
export class JwtToken {
static jwt: any;
static username:string="";

// constructor(jwt:any)
// {
//     JwtToken.jwt=jwt;
// }
// setJwt(jwt:string)
// {
//     this.jwt=jwt;
// }
// getJwt()
// {
//     return this.jwt;
// }
}
