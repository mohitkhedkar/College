package com.rey.secureApp.entity;

import java.time.LocalDateTime;
import java.util.List;

import javax.persistence.CascadeType;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.OneToMany;

@Entity
public class User {

	@Id
	private long id;
	private String username;
	private String password;
	private String role;
	private int authentication;
	private int otp;
	private String email;
	private LocalDateTime expiry;
	private boolean status;
	@OneToMany(cascade = CascadeType.ALL)
	private List<Data> data;
	public User() {
		super();
	}
	
	public User( String username, String password, String email) {
		super();
		
		this.username = username;
		this.password = password;
		this.role = "ROLE_stu";
		this.authentication = 0;
		this.otp = 0;
		this.email = email;
		this.status=true;
		
		
	}

	public long getId() {
		return id;
	}
	public void setId(int id) {
		this.id = id;
	}
	public String getUsername() {
		return username;
	}
	public void setUsername(String userName) {
		this.username = userName;
	}
	public String getPassword() {
		return password;
	}
	public void setPassword(String password) {
		this.password = password;
	}
	public String getRole() {
		return role;
	}
	public void setLoginrole(String loginRole) {
		this.role = loginRole;
	}
	
	public int getAuthentication() {
		return authentication;
	}
	public void setAuthentication(int authentication) {
		this.authentication = authentication;
	}
	public int getOtp() {
		return otp;
	}
	public void setOtp(int otp) {
		this.otp = otp;
	}
	public String getEmail() {
		return email;
	}
	public void setEmail(String email) {
		this.email = email;
	}

	public LocalDateTime getExpiry() {
		return expiry;
	}

	public void setExpiry(LocalDateTime expiry) {
		this.expiry = expiry;
	}

	public boolean getStatus() {
		return status;
	}

	public void setStatus(boolean status) {
		this.status = status;
	}
	
	public void setData(List<Data> data)
	{
		this.data=data;
	}
	public List<Data> getData()
	{
		return data;
	}
	@Override
	public String toString() {
		return "User [id=" + id + ", username=" + username + ", password=" + password + ", role=" + role
				+ "]";
	}
	
}
