// In Secondyear Computer Engineering class of M students, set A of students play cricket and set B of students play badminton. Write C/C++ program to find and display-
//  1. Set of students who play either cricket or  badminton or both
//  2. Set of students who play both cricket and badminton 
//  3. Set of students who play only cricket 
//  4. Set of students who play only badminton
//  5. Number of students who play neither cricket nor badminton(Note-While realizing the set duplicate entries are to avoided)

// Author: Mohit Khedkar

#include<iostream>
using namespace std;
class game
{
	private : int a,c,b,i,j,l;
	          int tot_stud[20],cric[10],bad[10],comple[20],uni[10],onlybad[10],onlycric[10];
    
    public : game();
	         void getdata();
             void uunion();
             void intersection();
             void onlybadminton();
             void uunion_comp();
             void onlycricket();
};

game::game(){
    l=0;
	a=0;
	c=0;
	b=0;
	i=0;
	j=0;
}

void game :: getdata(){
	cout<<"\nEnter the total no of students in class : ";
	cin>>a;
	for(i=0;i<a;i++)
	{
		tot_stud[i]=i+1;
	}
	
	cout<<"\nEnter the no of students playing cricket : ";
	cin>>c;
	cout<<"\nEnter the no of students playing badminton : ";
	cin>>b;
	cout<<"\nEnter the roll no of students playing cricket :";
	for(i=0;i<c;i++)
	{
		cin>>cric[i];
	}
	cout<<"\nEnter the roll no of students playing badminton :";
	for(i=0;i<b;i++)
	{
		cin>>bad[i];
	}
}

void game :: intersection ()
{   cout<<"\nRoll no of students playing badminton as well as cricket are : ";
	for(i=0;i<b;i++)
	{
		for(j=0;j<c;j++)
		{
			if(cric[j]==bad[i])
			{
			  cout<<cric[j]<<"   ";	
			}
		}
	}

}
void game :: uunion(){
	int j,flag=0;
		for(i=0;i<a;i++)
	{
		uni[i]=0;
	}
	for(i=0;i<c;i++)
	{   
		uni[l]=cric[i];
		++l;
		
	}
	
	for(j=0;j<b;j++)
	{
		for(i=0;i<c;i++)
		{
			if(bad[j]==cric[i])
		   {
			flag=1;
		   }
		}
		if(flag==0)
		{
			uni[l]=bad[j];
			l++;
		}
		flag=0;
	}
	cout<<"\nRoll no. of students playing either cricket or badminton or both are : ";
	for(i=0;i<l;i++)
	{
		cout<<uni[i]<<"   ";
	}
	
}

void game :: onlybadminton()
{   int flag=0,k=0,flag1=0;
    cout<<"\nRoll no of students playing only badminton are : ";
	for(i=0;i<b;i++)
	{
		for(j=0;j<c;j++)
		{
		   if(bad[i]==cric[j])
		   {
		   	   flag=1;
		   	   flag1++;
		   }
		}
		if(flag==0)
		   {
		   	    onlybad[k]=bad[i];
		   	    k++;
		   }	 
		flag=0;
		if(flag1==b)
		cout<<"NO ONE IS PLAYIG ONLY BADMINTON!!";
		
	}
	for(i=0;i<k;i++)
	{
		cout<<onlybad[i]<<"   ";
	}
}

void game :: onlycricket()
{   int flag=0,k=0,flag1=0;
    cout<<"\nRoll no of students playing only cricket are : ";
	for(i=0;i<c;i++)
	{
		for(j=0;j<b;j++)
		{
		   if(cric[i]==bad[j])
		   {
		   	   flag=1;
		   	   flag1++;
		   }
		}
		if(flag==0)
		   {
		   	    onlycric[k]=cric[i];
		   	    k++;
		   }	 
		flag=0;
		if(flag1==c)
		cout<<"NO ONE IS PLAYIG ONLY CRICKET!!";
	}
	for(i=0;i<k;i++)
	{
		cout<<onlycric[i]<<"   ";
	}
}

void game :: uunion_comp()
{   int flag=0,k=0;
     cout<<"\nRoll no of students playing neither cricket nor badminton are : ";
	for(i=0;i<a;i++)
	{
		for(j=0;j<l;j++)
		{
			if(tot_stud[i]==uni[j])
			{
			flag=1;
			}
		}
		if(flag==0)
		{
		  comple[k]=tot_stud[i];
		  k++;	
		}
		flag=0;
	}
	for(i=0;i<k;i++)
	{
		cout<<comple[i]<<"   ";//error in comple
	}
	
}
int main()
{
	game g1;
	g1.getdata();
    g1.intersection();	
    g1.uunion();
	g1.onlybadminton();
	g1.uunion_comp();
	g1.onlycricket();
	
}