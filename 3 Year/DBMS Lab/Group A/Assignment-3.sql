-- Assignment 3: Design at least 10 SQL queries for suitable database application using SQL DML statements: Insert, Select, Update, Delete with operators, functions, and set operator.
-- Author: Mohit Khedkar.

-- existing databases in system
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
7 rows in set (0.11 sec)

-- Creating new database for dml commands
mysql> create database dml_commands;
Query OK, 1 row affected (0.03 sec)

mysql> show databases;
+--------------------+
| Database           |
+--------------------+
| ddl_commands       |
| dml_commands       |
| information_schema |
| mysql              |
| performance_schema |
| sakila             |
| sys                |
| world              |
+--------------------+
8 rows in set (0.00 sec)

-- Switching to dml database
mysql> use dml_commands;
Database changed

-- Creating student_info table
mysql> use dml_commands;
Database changed
mysql> create table student_info(
    -> id INT AUTO_INCREMENT PRIMARY KEY,
    -> rollno INT NOT NULL,
    -> name VARCHAR(255),
    -> email VARCHAR(255)
    -> );
Query OK, 0 rows affected (0.14 sec)

mysql> show tables;
+------------------------+
| Tables_in_dml_commands |
+------------------------+
| student_info           |
+------------------------+
1 row in set (0.02 sec)

-- Inserting values in student_info
mysql> INSERT INTO student_info (rollno,name,email) VALUES ('81','mihir','mihir@gmail.com');
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO student_info (rollno,name,email) VALUES ('82','megha','megha@gmail.com');
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO student_info (rollno,name,email) VALUES ('95','mohit','mohit@gmail.com');
Query OK, 1 row affected (0.01 sec)

mysql> INSERT INTO student_info (rollno,name,email) VALUES ('98','madhur','madhur@gmail.com');
Query OK, 1 row affected (0.01 sec)


-- Select query in Mysql
mysql> SELECT * FROM student_info;
+----+--------+--------+------------------+
| id | rollno | name   | email            |
+----+--------+--------+------------------+
|  1 |     81 | mihir  | mihir@gmail.com  |
|  2 |     82 | megha  | megha@gmail.com  |
|  3 |     95 | mohit  | mohit@gmail.com  |
|  4 |     98 | madhur | madhur@gmail.com |
+----+--------+--------+------------------+
4 rows in set (0.00 sec)

-- Update function
mysql> UPDATE student_info
    -> SET name = 'hemanshu',email = 'hemanshu@gmail.com'
    -> WHERE id = 4;
Query OK, 1 row affected (0.02 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> SELECT * FROM student_info;
+----+--------+----------+--------------------+
| id | rollno | name     | email              |
+----+--------+----------+--------------------+
|  1 |     81 | mihir    | mihir@gmail.com    |
|  2 |     82 | megha    | megha@gmail.com    |
|  3 |     95 | mohit    | mohit@gmail.com    |
|  4 |     98 | hemanshu | hemanshu@gmail.com |
+----+--------+----------+--------------------+
4 rows in set (0.00 sec)

-- Delete operation 
mysql> DELETE FROM student_info WHERE name= 'megha';
Query OK, 1 row affected (0.01 sec)

mysql> SELECT * FROM student_info;
+----+--------+----------+--------------------+
| id | rollno | name     | email              |
+----+--------+----------+--------------------+
|  1 |     81 | mihir    | mihir@gmail.com    |
|  3 |     95 | mohit    | mohit@gmail.com    |
|  4 |     98 | hemanshu | hemanshu@gmail.com |
+----+--------+----------+--------------------+
3 rows in set (0.00 sec)

-- Using operators in update
mysql> UPDATE student_info
    -> SET name = 'sanket',email = 'sanket@gmail.com'
    -> WHERE id = 1 AND rollno= '81';
Query OK, 1 row affected (0.01 sec)
Rows matched: 1  Changed: 1  Warnings: 0

mysql> SELECT * FROM student_info;
+----+--------+----------+--------------------+
| id | rollno | name     | email              |
+----+--------+----------+--------------------+
|  1 |     81 | sanket   | sanket@gmail.com   |
|  3 |     95 | mohit    | mohit@gmail.com    |
|  4 |     98 | hemanshu | hemanshu@gmail.com |
+----+--------+----------+--------------------+
3 rows in set (0.00 sec)

-- using operatiors in SELECT
mysql> SELECT * FROM student_info WHERE id = 3 OR rollno = '95';
+----+--------+-------+-----------------+
| id | rollno | name  | email           |
+----+--------+-------+-----------------+
|  3 |     95 | mohit | mohit@gmail.com |
+----+--------+-------+-----------------+
1 row in set (0.00 sec)