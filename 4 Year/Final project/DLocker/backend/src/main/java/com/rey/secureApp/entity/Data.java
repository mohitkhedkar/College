package com.rey.secureApp.entity;

import javax.persistence.Entity;
import javax.persistence.Id;

@Entity
public class Data {

	@Id
	private long id;
	private String filename;
	private boolean status;
	private String username;
	private String link;
	public long getId() {
		return id;
	}
	public void setId(long id) {
		this.id = id;
	}
	public String getFilename() {
		return filename;
	}
	public void setFilename(String filename) {
		this.filename = filename;
	}
	public boolean isStatus() {
		return status;
	}
	public void setStatus(boolean status) {
		this.status = status;
	}
	@Override
	public String toString() {
		return "Data [id=" + id + ", filename=" + filename + ", status=" + status + "]";
	}
	public Data() {
		super();
		// TODO Auto-generated constructor stub
	}
	public Data( String filename,  String username, String link) {
		super();
		this.link=link;
		this.filename = filename;
		this.status = false;
		this.username=username;
	}

	public String getLink() {
		return link;
	}
	public void setLink(String link) {
		this.link = link;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String username) {
		this.username = username;
	}
	
}
