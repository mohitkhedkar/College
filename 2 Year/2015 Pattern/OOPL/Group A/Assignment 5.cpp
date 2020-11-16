// Write a C++ program create a calculator for an arithmetic operator (+, -, *, /).  The program should  take  two  operands  from  user  and  performs  the  operation  on  those  two  operands depending upon the operator entered byuser. Use a switch statement to select the operation. Finally, display the result. 
// Some sample interaction with the program might look like this:
// Enter first number, operator, second number: 10 / 3
// Answer = 3.333333
// Do another (y/n)? y
// Enter first number, operator, second number: 12 + 100
// Answer = 112
// Do another (y/n)? n

// Author : Mohit khedkar.

#include <iostream>
using namespace std;

int main()
{
	int a,b;
	int ch;
char choice;
	 cout<< "ENTER ANY TWO NO.";
	cin>>a>>b;
	do
	{
	cout<< "enter choices, 1 for sum , 2 for substract, 3 for multiply 2 for divide " ;
	cin>>ch;

	switch(ch)
	{
	case 1:
	{
		int sum = a+b;
		cout<< sum;
		break;
	}
	case 2:
	{
		int sub = a-b;
		cout<< sub;
		break;
	}
	case 3:
	{
		int mul = a*b;
		cout<< mul;
		break;
	}
	case 4:
	{
			int div = a/b;
			cout<< div;
			break;
	}

}
	cout<<"\nwant to countie or not?\n";
	cin>>choice;

	}while(choice=='y');
return 0;
}