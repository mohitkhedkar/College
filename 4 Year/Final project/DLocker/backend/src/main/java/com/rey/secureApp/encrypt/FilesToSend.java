package com.rey.secureApp.encrypt;


public class FilesToSend {
String type;
String base64;
public String getType() {
	return type;
}
public void setType(String type) {
	this.type = type;
}
public String getBase64() {
	return base64;
}
public void setBase64(String base64) {
	this.base64 = base64;
}
public FilesToSend(String type, String base64) {
	super();
	this.type = type;
	this.base64 = base64;
}

}
