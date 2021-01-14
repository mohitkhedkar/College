--Design at least 10 SQL queries for suitable database application using SQL DML statements: all types of Join, Sub-Query and View
-- Author: Mohit Khedkar.

-- continuing from Assignment 3 i.e database and table created and values added in the table

-- Existing Database
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

mysql> use dml_commands;
Database changed

-- Existing tables
mysql> show tables;
+------------------------+
| Tables_in_dml_commands |
+------------------------+
| student_info           |
+------------------------+
1 row in set (0.00 sec)

-- Creating new tables

-- creating customer table
mysql> CREATE TABLE customer(
    -> id INT PRIMARY KEY,
    -> name VARCHAR(25) NOT NULL,
    -> salary float NOT NULL
    -> );
Query OK, 0 rows affected (0.30 sec)

-- inserting values in Customer table
mysql> INSERT INTO customer VALUES (1,'Mohit',500000),
	->  (2,'Ajay',250000),
    ->  (3,'Rutuja',350000),
    ->  (4,'Hemanshu',353240);
Query OK, 4 rows affected (0.02 sec)
Records: 4  Duplicates: 0  Warnings: 0


mysql> SELECT * FROM customer;
+----+----------+--------+
| id | name     | salary |
+----+----------+--------+
|  1 | Mohit    | 500000 |
|  2 | Ajay     | 250000 |
|  3 | Rutuja   | 350000 |
|  4 | Hemanshu | 353240 |
+----+----------+--------+
4 rows in set (0.00 sec)

-- creating orders table
mysql> CREATE TABLE orders(
    -> order_id INT PRIMARY KEY,
    -> customer_id INT REFERENCES customers,
    -> amount INT NOT NULL
    -> );
Query OK, 0 rows affected (0.13 sec)

-- inserting values in orders table
mysql> INSERT INTO orders VALUES (1,2,200),
    -> (2,2,1200),
    -> (3,3,2300),
    -> (4,4,2100),
    -> (5,1,100);
Query OK, 5 rows affected (0.02 sec)
Records: 5  Duplicates: 0  Warnings: 0

mysql> SELECT * FROM orders;
+----------+-------------+--------+
| order_id | customer_id | amount |
+----------+-------------+--------+
|        1 |           2 |    200 |
|        2 |           2 |   1200 |
|        3 |           3 |   2300 |
|        4 |           4 |   2100 |
|        5 |           1 |    100 |
+----------+-------------+--------+
5 rows in set (0.00 sec)

-- JOIN OPERATIONS

-- INNER JOIN
mysql> SELECT name,salary,amount FROM customer INNER JOIN orders ON customer.id = orders.customer_id;
+----------+--------+--------+
| name     | salary | amount |
+----------+--------+--------+
| Ajay     | 250000 |    200 |
| Ajay     | 250000 |   1200 |
| Rutuja   | 350000 |   2300 |
| Hemanshu | 353240 |   2100 |
| Mohit    | 500000 |    100 |
+----------+--------+--------+
5 rows in set (0.00 sec)

-- LEFT JOIN
mysql> SELECT name,salary,amount FROM customer LEFT JOIN orders ON customer.id = orders.customer_id;
+----------+--------+--------+
| name     | salary | amount |
+----------+--------+--------+
| Mohit    | 500000 |    100 |
| Ajay     | 250000 |    200 |
| Ajay     | 250000 |   1200 |
| Rutuja   | 350000 |   2300 |
| Hemanshu | 353240 |   2100 |
+----------+--------+--------+
5 rows in set (0.00 sec)

-- RIGHT JOIN
mysql> SELECT name,salary,amount FROM customer RIGHT JOIN orders ON customer.id = orders.customer_id;
+----------+--------+--------+
| name     | salary | amount |
+----------+--------+--------+
| Ajay     | 250000 |    200 |
| Ajay     | 250000 |   1200 |
| Rutuja   | 350000 |   2300 |
| Hemanshu | 353240 |   2100 |
| Mohit    | 500000 |    100 |
+----------+--------+--------+
5 rows in set (0.00 sec)

-- FULL JOIN
mysql> SELECT name,salary,amount FROM customer FULL JOIN orders ON id = orders.customer_id;
+----------+--------+--------+
| name     | salary | amount |
+----------+--------+--------+
| Ajay     | 250000 |    200 |
| Ajay     | 250000 |   1200 |
| Rutuja   | 350000 |   2300 |
| Hemanshu | 353240 |   2100 |
| Mohit    | 500000 |    100 |
+----------+--------+--------+
5 rows in set (0.00 sec)

-- SELF JOIN
mysql> SELECT a.id,b.name,a.salary FROM customer a, customer b WHERE a.salary > b.salary;
+----+----------+--------+
| id | name     | salary |
+----+----------+--------+
|  1 | Ajay     | 500000 |
|  3 | Ajay     | 350000 |
|  4 | Ajay     | 353240 |
|  1 | Rutuja   | 500000 |
|  4 | Rutuja   | 353240 |
|  1 | Hemanshu | 500000 |
+----+----------+--------+
6 rows in set (0.00 sec)

-- CARTESIAN OR CROSS JOIN
mysql> SELECT id,name,amount FROM customer,orders;
+----+----------+--------+
| id | name     | amount |
+----+----------+--------+
|  1 | Mohit    |    200 |
|  2 | Ajay     |    200 |
|  3 | Rutuja   |    200 |
|  4 | Hemanshu |    200 |
|  1 | Mohit    |   1200 |
|  2 | Ajay     |   1200 |
|  3 | Rutuja   |   1200 |
|  4 | Hemanshu |   1200 |
|  1 | Mohit    |   2300 |
|  2 | Ajay     |   2300 |
|  3 | Rutuja   |   2300 |
|  4 | Hemanshu |   2300 |
|  1 | Mohit    |   2100 |
|  2 | Ajay     |   2100 |
|  3 | Rutuja   |   2100 |
|  4 | Hemanshu |   2100 |
|  1 | Mohit    |    100 |
|  2 | Ajay     |    100 |
|  3 | Rutuja   |    100 |
|  4 | Hemanshu |    100 |
+----+----------+--------+
20 rows in set (0.00 sec)


-- SUB QUERY OPERATION

-- SELECT
mysql> SELECT name FROM customer WHERE id IN (SELECT customer_id FROM orders);
+----------+
| name     |
+----------+
| Mohit    |
| Ajay     |
| Rutuja   |
| Hemanshu |
+----------+
4 rows in set (0.00 sec)

-- UPDATE
mysql> UPDATE customer SET salary=salary+1000 WHERE id IN (SELECT customer_id FROM orders);
Query OK, 4 rows affected (0.02 sec)
Rows matched: 4  Changed: 4  Warnings: 0

mysql> SELECT * FROM customer;
+----+----------+--------+
| id | name     | salary |
+----+----------+--------+
|  1 | Mohit    | 501000 |
|  2 | Ajay     | 251000 |
|  3 | Rutuja   | 351000 |
|  4 | Hemanshu | 354240 |
+----+----------+--------+
4 rows in set (0.00 sec)

-----------
--- END ---
-----------