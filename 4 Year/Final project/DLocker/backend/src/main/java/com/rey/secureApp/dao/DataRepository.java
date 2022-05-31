package com.rey.secureApp.dao;

import java.util.List;
import javax.transaction.Transactional;


import org.springframework.data.jpa.repository.JpaRepository;
import org.springframework.data.jpa.repository.Modifying;
import org.springframework.data.jpa.repository.Query;

import com.rey.secureApp.entity.Data;

public interface DataRepository extends JpaRepository<Data, Long> {

	public List<Data> findByStatus(boolean status);

	public Data findByFilename(String filename);
	
	public List<Data> findByUsername(String username);
	
//	@Modifying
//	@Transactional
//	@Query("select Data where userid=?1 and filename=?2")
	public Data findByLink(String link);
}
