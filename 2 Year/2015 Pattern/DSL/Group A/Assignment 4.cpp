// Set  A=(1, 3,  a,  s,  t,  i}  represent  alphanumeric  characters  permitted  to be  used  to set  the password of length.
//  Write C/C++ program to generate all possible passwords

// Author: Mohit Khedkar

#include<iostream>
using namespace std;
int main()
{
	char pass[]={'1','3','a','s','t','i'};
	int i,j,k,l,m,count=0;
	for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			for(k=0;k<5;k++)
			{
				for(l=0;l<5;l++)
				{
					for(m=0;m<5;m++)
					{
					   cout<<pass[i]<<pass[j]<<pass[k]<<pass[l]<<pass[m]<<"\n";	
					   count++;
					}
				}
			}
		}
	}
	cout<<"\nTotal no. of passwords generated : ";
	cout<<count;
}