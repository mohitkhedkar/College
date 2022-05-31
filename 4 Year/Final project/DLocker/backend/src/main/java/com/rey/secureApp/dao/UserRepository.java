package com.rey.secureApp.dao;

import java.time.LocalDateTime;

import java.util.List;

import javax.transaction.Transactional;

import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;

import com.rey.secureApp.entity.User;

public interface UserRepository extends JpaRepository<User, Long> {

	User findByUsername(String UserName);
	
	
	List<User> findByEmail(String email);
	
	@Modifying
	@Transactional
	@Query("update User set otp= ?1 where email=?2")
	void setOtp(int otp, String email);
	
	@Modifying
	@Transactional
	@Query("update User set authentication=1 where email=?1")
	void setAuthentication(String email);
	
	@Modifying
	@Transactional
	@Query("update User set role=?2 where username=?1")
	void setRole(String username, String role);
	
	@Modifying
	@Transactional
	@Query("update User set otp=?2, expiry=?3 where email=?1")
	boolean setExpiry(String email, int otp, LocalDateTime expiry);
	
	@Modifying
	@Transactional
	@Query("update User set password=?2 where email=?1")
	void setPassword(String email, String password);
	
	@Modifying
	@Transactional
	@Query("update User set status=?2 where username=?1")
	void setStatus(String username,boolean status);
	
//	@Modifying
//	@Transactional
//	@Query("select id from  User where username=?1")
//	int getByUsername(String username);
	
}
