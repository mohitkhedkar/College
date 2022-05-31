package com.rey.secureApp.jwt;

public class Token {
private String error="";
private String jwt;
private String role;
public String getError() {
	return error;
}
public void setError(String error) {
	this.error = error;
}
public String getJwt() {
	return jwt;
}
public void setJwt(String jwt) {
	this.jwt = jwt;
}
public String getRole() {
	return role;
}
public void setRole(String role) {
	this.role = role;
}
public Token() {
	super();
	// TODO Auto-generated constructor stub
}
public Token(String error, String jwt, String role) {
	super();
	this.error = error;
	this.jwt = jwt;
	this.role = role;
}

}
