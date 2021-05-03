-- Cursors: (All types: Implicit, Explicit, Cursor FOR Loop, Parameterized Cursor) Write a PL/SQL block of code using parameterized Cursor, that will merge the data available in the newly created table N_RollCall with the data available in the table O_RollCall. If the data in the first table already exist in the second table then that data should be skipped. Frame the separate problem statement for writing PL/SQL block to implement all types of Cursors inline with above statement. The problem statement should clearly state the requirements.

-- Author: Mohit Khedkar

mysql> use mohitDB;
Reading table information for completion of table and column 
names
You can turn off this feature to get a quicker startup with -A
Database changed
mysql> create table o_rollcall(roll_no int,name 
varchar(20),address varchar(20));
Query OK, 0 rows affected (0.28 sec)
mysql> create table n_rollcall(roll_no int,name 
varchar(20),address varchar(20));
Query OK, 0 rows affected (0.27 sec)
mysql> insert into o_rollcall('1','Hitesh','Nandura');
ERROR 1064 (42000): You have an error in your SQL syntax; 
check the manual that corresponds to your MySQL server version
for the right syntax to use near ''1','Hitesh','Nandura')' at 
line 1
mysql> insert into o_rollcall values('1','Hitesh','Nandura');
Query OK, 1 row affected (0.05 sec)
mysql> insert into o_rollcall values('2','Piyush','MP');
Query OK, 1 row affected (0.06 sec)mysql> insert into o_rollcall values('3','Ashley','Nsk');
Query OK, 1 row affected (0.05 sec)
mysql> insert into o_rollcall values('4','Kalpesh','Dhule');
Query OK, 1 row affected (0.05 sec)
mysql> insert into o_rollcall values('5','mohit','Aurangabad');
Query OK, 1 row affected (0.04 sec)
mysql> delimiter //
mysql> create procedure p3(in r1 int)
 -> begin
 -> declare r2 int;
 -> declare exit_loop boolean;
 -> declare c1 cursor for select roll_no from o_rollcall 
where roll_no>r1;
 -> declare continue handler for not found set 
exit_loop=true;
 -> open c1;
 -> e_loop:loop
 -> fetch c1 into r2;
 -> if not exists(select * from n_rollcall where 
roll_no=r2)
 -> then
 -> insert into n_rollcall select * from o_rollcall where 
roll_no=r2;
 -> end if;
 -> if exit_loop
 -> then
 -> close c1;
 -> leave e_loop;
 -> end if;
 -> end loop e_loop; -> end
 -> //
Query OK, 0 rows affected (0.00 sec)
mysql> call p3(3); 
-> //
Query OK, 0 rows affected (0.10 sec)
mysql> select * from n_rollcall;
 -> //
+---------+---------+-------------+
| roll_no | name    | address     |
+---------+---------+-------------+
| 4       | Kalpesh | Dhule       |
| 5       | mohit   | Aurangabad  |
+---------+---------+-------------+
2 rows in set (0.00 sec)
mysql> call p3(0);
 -> //
Query OK, 0 rows affected (0.22 sec)
mysql> select * from n_rollcall;
 -> //
+---------+---------+--------------+
| roll_no | name    | address      |
+---------+---------+--------------+
| 4       | Kalpesh | Dhule        |
| 5       | mohit   | Aurangabad   |
| 1       | Hitesh  | Nandura      |
| 2       | Piyush  | MP           |
| 3       | Ashley  | Nsk          |
+---------+---------+--------------+
5 rows in set (0.00 sec)

mysql> insert into o_rollcall values('6','Patil','Kolhapur');
 -> //
Query OK, 1 row affected (0.04 sec)

mysql> call p3(4);
 -> //
Query OK, 0 rows affected (0.05 sec)

mysql> select * from n_rollcall;
 -> //
+---------+---------+-----------+
| roll_no | name    | address   |
+---------+---------+-----------+
| 4       | Kalpesh | Dhule     |
| 5       | mohit   | Aurangabad|
| 1       | Hitesh  | Nandura   |
| 2       | Piyush  | MP        |
| 3       | Ashley  | Nsk       |
| 6       | Patil   | Kolhapur  |
+---------+---------+-----------+
6 rows in set (0.00 sec)