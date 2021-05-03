-- Unnamed PL/SQL code block: Use of Control structure and Exception handling is mandatory. Write a PL/SQL block of code for the following requirements:-
--     Schema:
--     1. Borrower(Rollin, Name, DateofIssue, NameofBook, Status)
--     2. Fine(Roll_no,Date,Amt)
--     - [ ] Accept roll_no & name of book from user.
--     - [ ] Check the number of days (from date of issue), if days are between 15 to 30 then fine
--     amount will be Rs 5per day.
--     - [ ] If no. of days>30, per day fine will be Rs 50 per day & for days less than 30, Rs. 5 per
--     day.
--     - [ ] After submitting the book, status will change from I to R.
--     - [ ] If condition of fine is true, then details will be stored into fine table.
--     Frame the problem statement for writing PL/SQL block inline with above statement.

-- Author: Mohit Khedkar

mysql> use mohitDB;

Reading table information for completion of table and column 
names
You can turn off this feature to get a quicker startup with -A
Database changed

mysql> delimiter //

mysql> call B1(1,'TOC')
 -> //
+-----------+
| NOT FOUND |
+-----------+
| NOT FOUND |
+-----------+
1 row in set (0.35 sec)
Query OK, 0 rows affected (0.41 sec)
mysql> select * from Borrower;
 -> //
+---------+-----------+-----------+-----------+----------+
| roll_no | name      | DOI       | book_name | status   |
+---------+-----------+-----------+-----------+----------+
| 12      | patel     | 2020-07-01 | xyz      | issued   |
| 14      | shinde    | 2020-06-01 | oop      | issued   |
| 16      | bhangale  | 2020-05-01 | coa      | returned |
| 18      | rebello   | 2020-06-15 | toc      | returned |
| 20      | patil     | 2020-05-15 | mp       | issued   |
+---------+----------+------------+-----------+----------+
5 rows in set (0.00 sec)
mysql> show tables;
 -> //
+-------------------+
| Tables_in_mohitDB |
+-------------------+
| Borrower          |
| Employee          |
| Fine              |
| TE                |
| _master           |
| auto              |
| c_master          |
| capital           |
| customer          |
| orders            |
| person            |
| product_master    |
| state             |
+-------------------+
13 rows in set (0.00 sec)

mysql> create procedure B(roll_new int,book_name varchar(20))
 -> begin
 -> declare X integer;
 -> declare continue handler for not found
 -> begin
 -> select 'NOT FOUND';
 -> end;
 -> select datediff(curdate(),DOI) into X from Borrower 
where roll_no=roll_new;
 -> if (X>15&&X<30)
 -> then
 -> insert into Fine values(roll_new,curdate(),(X*5));
 -> end if;
 -> if (X>30)
 -> then
 -> insert into Fine values(roll_new,curdate(),(X*50));
 -> end if;
 -> update Borrower set status='returned' where 
roll_no=roll_new;
 -> end;
 -> //
Query OK, 0 rows affected (0.02 sec)
mysql> call B(12,'xyz'); -> //
Query OK, 1 row affected (0.42 sec)
mysql> select * from Fine;//
+---------+------------+--------+
| roll_no | fine_date  | amount |
+---------+------------+--------+
| 12      | 2020-07-28 | 135    |
+---------+------------+--------+
1 row in set (0.00 sec)
mysql> select * from Borrower;//
+---------+----------+------------+-----------+----------+
| roll_no | name     | DOI        | book_name | status   |
+---------+----------+------------+-----------+----------+
| 12      | patel    | 2020-07-01 | xyz       | returned |
| 14      | shinde   | 2020-06-01 | oop       | issued   |
| 16      | bhangale | 2020-05-01 | coa       | returned |
| 18      | rebello  | 2020-06-15 | toc       | returned |
| 20      | patil    | 2020-05-15 | mp        | issued   |
+---------+----------+------------+-----------+----------+
5 rows in set (0.00 sec)

mysql> call B(20,'patil');
 -> //
Query OK, 1 row affected (0.35 sec)

mysql> select * from Fine;//
+---------+------------+--------+
| roll_no | fine_date  | amount  |
+---------+------------+--------+
| 12      | 2020-07-28 | 135    |  
| 20      | 2020-07-28 | 3700   |
+---------+------------+--------+
2 rows in set (0.00 sec)
mysql> select * from Borrower;//
+---------+----------+------------+-----------+----------+
| roll_no | name     | DOI        | book_name | status   |
+---------+----------+------------+-----------+----------+
| 12      | patel    | 2020-07-01 | xyz       | returned |
| 14      | shinde   | 2020-06-01 | oop       | issued   |
| 16      | bhangale | 2020-05-01 | coa       | returned |
| 18      | rebello  | 2020-06-15 | toc       | returned |
| 20      | patil    | 2020-05-15 | mp        | returned |
+---------+----------+------------+-----------+----------+
5 rows in set (0.00 sec)