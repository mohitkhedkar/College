// Crete User defined exception to check the following conditions and throw the exception if the criterion does not meet.
// 1. User has age between 18 and 55
// 2. User stays has income between Rs. 50,000 –Rs. 1,00,000 per month
// 3. User stays in Pune/ Mumbai/ Bangalore / Chennai
// 4. User has 4-wheeler Accept age, Income, City, Vehicle from the user and check for the conditions mentionedabove. If any of the condition not met then throw the exception. 

// Author: Mohit Khedkar.

#include<iostream>
#include<string.h>
using namespace std;
class myexception
{
private:
	int exception;
	char disc[10];
public :

	myexception(int id,char d[])		//parameterised Constructor
	{
		exception=id;
		strcpy(disc,d);
	}
	void disp_exception()
	{
		cout<<disc<<exception;	
	}
};


class user
{
private :
	int age ;
	int income ;
	char city[20];
	int vehicle;
public :
	void read()
	{
		int flag=1;
		while (flag)
		{
			try
			{
				
				cout<<"\n Enter the age of the person ";
				cin>>age ;
				if(age<18||age>55)
					{
						myexception m1(1,(char *)"Invalid age");
						throw m1;	
					}	
				else
					flag=0;
			}
			catch(myexception m1)
			{
				m1.disp_exception();
			}
		}	
		flag =1;
		while(flag)
		{
			try
			{
					cout<<"\n Enter the income of the person :";
					cin>>income;
				if(income<50000||income>100000)
					{
						myexception m2(2,(char *)"invlalid income");
						throw m2;		
					}
				else
					flag=0;	
			}	
			catch(myexception m2)
			{
				m2.disp_exception ();
			}
		}
		
		flag=1;
		while(flag)
		{
			try
			{
				cout<<"\n Enter the city name : (kindly enter 1st alphabate as a capital)";
				cin>>city;
				if(strcmp("Pune",city)==0||strcmp("Mumbai",city)==0||strcmp("Chennai",city)==0||strcmp("Bangalore",city)==0)			
					{
						flag=0;				
					}
				else
					{
					myexception m3(3,(char*)"invlalid City");
					throw m3;
					}
			}	
			catch(myexception m3)
			{
				m3.disp_exception();			
			}
		}
	
		flag=1;
		while(flag)
		{
			try
			{		
				cout<<"\n Which vehicle user has :";		
				cin>>vehicle;
				if(vehicle==4)
				{
					flag=0	;	
				}		
				else
				{
					myexception m4(4,(char *)"invlalid ");
						throw m4;		
				}
			}		
			catch(myexception m4)
			{
				m4.disp_exception();			
			}
		}		
	}
	
	void display()
	{
	cout<<"\n Age 		: 	"<<age;
	cout<<"\n Income 	:	"<<income;
	cout<<"\n City 		:	"<<city;
	cout<<"\n Vehicle	:	"<<vehicle;		
	}		
};


int main()
{
user u;
u.read();
u.display();
return 0;
}