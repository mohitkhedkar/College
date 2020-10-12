# Object Oriented Programming Lab (OOPL).

## List of Assignments

## [Group A](https://github.com/mohitkhedkar/College/tree/main/2%20Year/OOPL/Group%20A)

### Assignment-2 :
- [X] Implement a class Complex which represents the Complex Number data type. 
Implement the following operations:
1. Constructor (including a default constructor which creates the complex number 0+0i).
2. Overloaded operator+ to add two complex numbers.
3. Overloaded operator* to multiply two complex numbers.
4. Overloaded << and >> to print and read Complex Numbers. 

### Assignment-3 : 
- [X] Implement a class Quadratic that represents degree two polynomials i.e polynomials of type ax2+bx+c. The class will require three data members corresponding to a, b and c. Implement the following operations:
1. A constructor (including a default constructor which creates the 0 polynomial).
2. Overloaded operator+ to add two polynomials of degree 2.
3. Overloaded << and >> to print and read polynomials. To do this, you will need to decide what you want your input and output format to look like.
4. A function eval that computes the value of apolynomial for a given value of x.
5. A function that computes the two solutions of the equation ax2+bx+c=0.

### Assignment-4 : 
- [X] Implement a class CppArray which is identical to a one-dimensional C++ array (i.e., the index set is a set of consecutive integers starting at 0) except for the following :
1. It performs range checking.
2. It allows one to be assigned to another array through the use of the assignment operator (e.g. cp1= cp2)
3. It supports a function that returns the size of the array.
4. It allows the reading or printing of array through the use of coutand cin

### Assignment-5 : 
- [ ] Write a C++ program create a calculator for an arithmetic operator (+, -, *, /).  The program should  take  two  operands  from  user  and  performs  the  operation  on  those  two  operands depending upon the operator entered byuser. Use a switch statement to select the operation. Finally, display the result. 
Some sample interaction with the program might look like this:
Enter first number, operator, second number: 10 / 3
Answer = 3.333333
Do another (y/n)? y
Enter first number, operator, second number: 12 + 100
Answer = 112
Doanother (y/n)? n

### Assignment-6 : 
- [X] Develop  an  object  oriented  program  in  C++  to  create  a  database  of  student    information system  containing the following information: Name, Roll number, Class, division,  Date of Birth, Blood group, Contact address, telephone number, driving license no. etc Construct the database  with  suitable  member  functions  for  initializing  and  destroying  the  data  viz constructor, default constructor, Copy constructor, destructor, static member functions, friend class, this pointer, inline code and dynamic memory allocation operators-new and delete.

### Assignment-7 : 
- [ ] Create a class template to represent a generic vector. Include following member functions:
1. To create the vector.
2. To modify the value of a given element
3. To multiply by a scalar value
4. To display the vector in the form (10,20,30,...)

### Assignment-8 : 
- [ ] Create a class Rational Number (fractions) with the following capabilities:
1.  Create  a  constructor  that  prevents  a  0  denominator  in  a  fraction,  reduces  or  simplifies fractions thatare not in reduced form and avoids negative denominators.
2. Overload the addition, subtraction, multiplication and division operators for this class.
3. Overload the relational and equality operators for this class

### Assignment-9 : 
- [X] Imagine a publishing company which does marketing for book and audiocassette versions. Create a class publication that stores the title (a string) and price (type float) of a publication. From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float). 
Write a program  that instantiates the book and  tape classes,  allows user to  enter data  and displays the data members. If an exception is caught, replace all the data member values with zero values. 

### Assignment-10 : 
- [ ] Write a function inC++ to count and display the number of lines not starting with alphabet 'A' present in a text file "STORY.TXT".
Example: If the file "STORY.TXT" contains the following lines,
    The roses are red.
    A girl is playing there.
    There is a playground.
    An aeroplane is in the sky.
    Numbers are not allowed in the password.
    The function should display the output as 3.

### Assignment-11 : 
- [ ] Write C++   Program with base class convert declares two variables, val1 and val2, which hold the initial and converted values, respectively. It also defines the functions getinit( ) and getconv( ), which return the initial value and the converted value. These elements of convert are fixed and applicable to all derived classes that will inherit convert. However, the function that will actually perform the conversion, compute( ), is a pure virtual function that must be defined  by  the  classes  derived  from  convert.  The  specific  nature  of  compute(  )  will  be determined by what type of conversion is taking place.

### Assignment-12 : 
- [ ] A book shop maintains the inventory of books that are being sold at the shop. The list includes details such as author, title, price, publisher and stock position. Whenever a customer wants a book, the sales person inputs the title and author and the system searches the list anddisplays whether it is available or not. If it is not, an appropriate message is displayed. If it is, then the system  displays  the  book  details  and  requests  for  the  number  of  copies  required.  If  the requested copies book details and requests for the number of copies required. If the requested copies are available, the total cost of the requested copies is displayed; otherwise the message ―Required copies not in stock‖ is displayed. Design a system using a class called books with suitable  member  functions  and  Constructors.  Use  new  operator  in  constructors  to  allocate memory space required. Implement C++ program for the system.

### Assignment-13 : 
- [X] Create employee bio-data using following classes 
1. Personal record 
2. Professional record 
3. Academic record Assume appropriatedata members and member function to accept required data & print bio-data. 
Create bio-data using multiple inheritance using C++.

## [Group B](https://github.com/mohitkhedkar/College/tree/main/2%20Year/OOPL/Group%20B)

### Assignment-14 : 
- [X] Create User defined exception to check the following conditions and throw the exception if the criterion does not meet.
1. User has age between 18 and 55
2. User stays has income between Rs. 50,000 –Rs. 1,00,000 per month
3. User stays in Pune/ Mumbai/ Bangalore / Chennai
4. User has 4-wheeler Accept age, Income, City, Vehicle from the user and check for the conditions mentionedabove. If any of the condition not met then throw the exception. 

### Assignment-15 : 
- [X] Write a menu driven program that will create a data file containing the list of telephone numbers in the following form
    John    23456
    Ahmed   9876
    ...........    .........
Use a class object to store each set of data, access the file created and implement the following tasks     
1. Determine the telephone number of specified person
2. Determine the name if telephone number is known
3. Update the telephone number, whenever there is a change.

### Assignment-16 : 
- [ ] Write a C++ program that creates an output file, writes information to it, closes the file and open it again as an input file and read the information from the file.

### Assignment-17 : 
- [ ] Write a C++ program using command line arguments to search for a word in a file and replace it with the specified word. The usage of the program is shown below. $  change <old word> <new word> <file name>

### Assignment-18 : 
- [X] Write a function template selection Sort. Write a program that inputs, sorts and outputs an integerarray and a float array.

### Assignment-19 : 
- [X] You are the owner of a hardware store and need to keep an inventory that can tell you what different tools you have, how many of each you have on hand and the cost of each one. Write a program that initializes the random-access file hardware.dat to 100 empty records, lets you input the data concerning each tool, enables you to list all your tools, lets you delete a record for a tool that you no longer have and lets you update any information in the file. The tool identification number should be the record number. Use the  following information  to  start your file:
    Record#    Tool name    Quantity    Cost
    3       Electric sander    7        57.98
    17      Hammer             76       11.99
    24      Jig saw            21       11.00
    39      Lawn mower         3        79.50
    56      Power saw          18       99.99

## [Group C](https://github.com/mohitkhedkar/College/tree/main/2%20Year/OOPL/Group%20C)

### Assignment-20 :
- [X] Write C++ program using STL for implementation of Singly, doubly and circular linked list.

### Assignment-21 :
Write C++ program using STL for implementation of stack & queue using SLL 

### Assignment-22 :
- [X] Write C++ program using STL toadd binary numbers (assume one bit as one number); use STL stack.

### Assignment-23 :
- [X] Write C++ program using STL  for Dqueue (Double ended queue)

### Assignment-24 :
- [X]  Write C++ program using STL for Sorting and searching with user-defined records such as Person Record (Name, birth date, telephone no), item record (item code, item name, quantity and cost)

## Mini-projects

### Assignment-25 :
- [ ] Design and develop the Tic-Tac-Toe Game using C++

### Assignment-26 :
- [ ] Develop a Supermarket Billing System using C++.  The key features of this application are listed below :
1. Bill Report: It shows the bill report of all the items added in supermarket billing system.
2. Add, Remove orEdit items: With this feature one can add, remove and modify item details. In add items, one can add information or details such as item no., item name, manufacturing date, price, quantity, tax percent, and many more.
3. Show item details: This feature allows users to see the items and the corresponding details given for the item while adding the item.Use file to store the data.

### Assignment-27 :
- [ ] Design an E-mail Verifier which accepts the email address from the user. Depending upon the input given by user display appropriate results. Use the following concepts in the Project –Constructor, Destructor, new, delete, exceptional handling, string handling functions, etc. 

### Assignment-28 :
- [x] Design and Develop Library Management system using OOP Concepts.

### Assignment-29 :
- [ ] Write a C++ program to implement a small database mini project to understand persistent objects  and  operations  on  sequential  files  (ex-library  information,  inventory  systems, automated banking system, reservation systems etc.) For example, write a program to create a database for reservation system using information such as Name, sex, age, starting place of journey  and  destination.  Program  should  have  following  facilities  
1.  To  display  entire passenger list 
2. To display particular record 
3. To update record 
4. To delete and sort record. Use Exception Handling for data verification
