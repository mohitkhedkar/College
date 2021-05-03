# Database Management System Lab (DBMS Lab).

## List of Assignments

## Group A

### Assignment-1 :
- [x] Study of Open Source Relational Databases : MySQL

### Assignment-2 :
- [x] Design and Develop SQL DDL statements which demonstrate the use of SQL objects such as Table, View, Index, Sequence, Synonym

### Assignment-3 :
- [x] Design at least 10 SQL queries for suitable database application using SQL DML statements: Insert, Select, Update, Delete with operators, functions, and set operator.

### Assignment-4 :
- [x]  Design at least 10 SQL queries for suitable database application using SQL DML statements: all types of Join, Sub-Query and View

### Assignment-5 :
- [x] Unnamed PL/SQL code block: Use of Control structure and Exception handling is mandatory. Write a PL/SQL block of code for the following requirements:-
    Schema:
    1. Borrower(Rollin, Name, DateofIssue, NameofBook, Status)
    2. Fine(Roll_no,Date,Amt)
    - [x] Accept roll_no & name of book from user.
    - [x] Check the number of days (from date of issue), if days are between 15 to 30 then fine
    amount will be Rs 5per day.
    - [x] If no. of days>30, per day fine will be Rs 50 per day & for days less than 30, Rs. 5 per
    day.
    - [x] After submitting the book, status will change from I to R.
    - [x] If condition of fine is true, then details will be stored into fine table.
    Frame the problem statement for writing PL/SQL block inline with above statement.   

### Assignment-6 :
- [x] Cursors: (All types: Implicit, Explicit, Cursor FOR Loop, Parameterized Cursor) Write a PL/SQL block of code using parameterized Cursor, that will merge the data available in the newly created table N_RollCall with the data available in the table O_RollCall. If the data in the first table already exist in the second table then that data should be skipped. Frame the separate problem statement for writing PL/SQL block to implement all types of Cursors inline with above statement. The problem statement should clearly state the requirements.

### Assignment-7 :
- [x] PL/SQL Stored Procedure and Stored Function. Write a Stored Procedure namely proc_Grade for the categorization of student. If marks scored by students in examination is <=1500 and marks>=990 then student will be placed in distinction category if marks scored are between 989 and900 category is first class, if marks 899 and 825 category is Higher Second Class Write a PL/SQL block for using procedure created with above requirement. Stud_Marks(name, total_marks) Result(Roll,Name, Class) Frame the separate problem statement for writing PL/SQL Stored Procedure and function, inline with above statement. The problem statement should clearly state the requirements

### Assignment-8 :
- [x] Database Trigger (All Types: Row level and Statement level triggers, Before and After Triggers). Write a database trigger on Library table. The System should keep track of the records that are being updated or deleted. The old value of updated or deleted records should be added in Library_Audit table. Frame the problem statement for writing Database Triggers of all types, in-line with above statement. The problem statement should clearly state the requirements.

## Group B

### Assignment-1 :
- [x]  Study of Open Source NOSQL Database: MongoDB (Installation, Basic CRUD operations,Execution)

### Assignment-2 :
- [x] Design and Develop MongoDB Queries using CRUD operations. (Use CRUD operations, SAVE method, logical operators)

### Assignment-3 :
- [x]  Implement aggregation and indexing with suitable example using MongoDB.

### Assignment-4 :
- [x] Create simple objects and array objects using JSON

### Assignment-5 :
- [x] Design and Implement any 5 query using MongoDB

### Assignment-6 :
- [x] Implement Map reduces operation with suitable example using MongoDB.

### Assignment-7 :
- [ ] Encode and Decode JSON Objects using Java/Perl/PHP/Python/Ruby

## Group C: Mini Project

### Assignment-1 :
- [ ]  Write a program to implement MogoDB database connectivity with PHP/python/Java. Implement Database navigation operations (add, delete, edit etc. ) using ODBC/JDBC.

### Assignment-2 :
- [ ] Implement MYSQL/Oracle database connectivity with PHP/ python/Java Implement Database navigation operations (add, delete, edit,) using ODBC/JDBC.

### Assignment-3 :
- [ ] Using the database concepts covered in Part-I & Part-II & connectivity concepts covered in Part C, students in group are expected to design and develop database application with following details:
  Requirement Gathering and Scope finalization
    Database Analysis and Design:
   
   - [ ]  Design Entity Relationship Model, Relational Model, Database Normalization
    Implementation :
   
   - [ ]   Front End : Java/Perl/PHP/Python/Ruby/.net
   
   - [ ]   Backend : MongoDB/MYSQL/Oracle
   
   - [ ]   Database Connectivity : ODBC/JDBC
    
   - [ ]   Testing : Data Validation
         Group of students should submit the Project Report which will be consist of documentation related to different phases of Software Development Life Cycle: Title of the Project, Abstract, Introduction, scope, Requirements, Data Modeling features, Data Dictionary, Relational Database Design, Database Normalization, Graphical User Interface, Source Code, Testing document, Conclusion. Instructor should maintain progress report of mini project throughout the semester from project group and assign marks as a part of the term work

### Assignment-4 :
- [x] Implementing Student Attendance Management System using Mysql database connectivity with PHP.

  * [Project Repo](https://github.com/mohitkhedkar/Student-Attendance-Management-System)