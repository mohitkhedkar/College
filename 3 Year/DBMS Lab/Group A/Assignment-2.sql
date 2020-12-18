-- Assignment 2: Design and Develop SQL DDL statements which demonstrate the use of SQL objects such as Table, View, Index, Sequence, Synonym
-- Author: Mohit Khedkar.

-- existing databases in system
mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| information_schema |
| mysql              |
| performance_schema |
| sakila             |
| sys                |
| world              |
+--------------------+

-- creating the new database schema
mysql> CREATE DATABASE ddl_commands;
Query OK, 1 row affected (0.02 sec)

mysql> show databases;

+--------------------+
| Database           |
+--------------------+
| ddl_commands       |
| information_schema |
| mysql              |
| performance_schema |
| sakila             |
| sys                |
| world              |
+--------------------+
7 rows in set (0.00 sec)

-- changing the database to ddl_commands
mysql> use ddl_commands;
Database changed

-- creating the table of student_info with rollno and name
mysql> CREATE TABLE student_info(
    -> rollno INT PRIMARY KEY,
    -> name VARCHAR(255) NOT NULL,
    -> ADD email VARCHAR(255)
    -> );
Query OK, 0 rows affected (0.43 sec)

mysql> show tables;
+------------------------+
| Tables_in_ddl_commands |
+------------------------+
| student_info           |
+------------------------+
1 row in set (0.01 sec)

-- Creating a view
mysql> CREATE VIEW view_student_info as (
    -> select rollno from student_info);
Query OK, 0 rows affected (0.01 sec)

mysql> desc view_student_info;
+--------+------+------+-----+---------+-------+
| Field  | Type | Null | Key | Default | Extra |
+--------+------+------+-----+---------+-------+
| rollno | int  | NO   |     | NULL    |       |
+--------+------+------+-----+---------+-------+
1 row in set (0.01 sec)

mysql> desc student_info;
+--------+--------------+------+-----+---------+-------+
| Field  | Type         | Null | Key | Default | Extra |
+--------+--------------+------+-----+---------+-------+
| rollno | int          | NO   | PRI | NULL    |       |
| name   | varchar(255) | NO   |     | NULL    |       |
| email  | varchar(255) | YES  |     | NULL    |       |
+--------+--------------+------+-----+---------+-------+
3 rows in set (0.00 sec)

-- Creating Index

mysql> CREATE INDEX idx_name ON student_info(name);
Query OK, 0 rows affected (0.36 sec)
Records: 0  Duplicates: 0  Warnings: 0

mysql> desc student_info;
+--------+--------------+------+-----+---------+-------+
| Field  | Type         | Null | Key | Default | Extra |
+--------+--------------+------+-----+---------+-------+
| rollno | int          | NO   | PRI | NULL    |       |
| name   | varchar(255) | NO   | MUL | NULL    |       |
| email  | varchar(255) | YES  |     | NULL    |       |
+--------+--------------+------+-----+---------+-------+
3 rows in set (0.01 sec)

-- Creating Sequence
	-- Creating new table
mysql> CREATE TABLE info(
    -> id INT AUTO_INCREMENT PRIMARY KEY,
    -> rollno INT NOT NULL,
    -> name VARCHAR(255)
    -> );
Query OK, 0 rows affected (0.10 sec)

mysql> show tables
    -> ;
+------------------------+
| Tables_in_ddl_commands |
+------------------------+
| info                   |
| student_info           |
| view_student_info      |
+------------------------+
3 rows in set (0.01 sec)

-- Inserting values in table
mysql> INSERT INTO info (rollno, name) VALUES ('081','mihir');
Query OK, 1 row affected (0.03 sec)

mysql> INSERT INTO info (rollno, name) VALUES ('082','megha');
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO info (rollno, name) VALUES ('083','sanket');
Query OK, 1 row affected (0.01 sec)

-- Sequence created in id column 
mysql> SELECT * FROM info;
+----+--------+--------+
| id | rollno | name   |
+----+--------+--------+
|  1 |     81 | mihir  |
|  2 |     82 | megha  |
|  3 |     83 | sanket |
+----+--------+--------+
3 rows in set (0.00 sec)