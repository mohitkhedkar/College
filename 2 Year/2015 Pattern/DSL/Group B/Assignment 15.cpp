// The ticket booking system of Cinemax theater has to be implemented using C++ program. There are 10 rows and 7 seats in each row. Doubly circular linked list has to be maintained to keep track of free seats at rows. Assume some random booking to start with. Use array to store pointers (Head pointer) to each row.  On demand 

//  1. The list of available seats is to be displayed
//  2. The seats are to be booked
//  3. The booking can be cancelled. 

//  Author : Mohit khedkar.

#include<iostream>
using namespace std;
class node
{
	node*next,*prev;
	int data;
	public:
	node(int x)
	{
		next=prev=NULL;
		data=x;
	}
	friend class ticket;
};
class ticket
{
	node*head[10],*rear[10];
	public:
	ticket()
	{
		for(int i=0;i<10;i++)
		{
			head[i]=NULL;
		}
	
	}
	void creat();
	void show();
	void booking();
	void available();
	void booked();
	void show1();
	void cancelbooking();
};
void ticket::creat()
{
	node*p;
	for(int x=0;x<10;x++)
	{ 
		head[x]=new node(0);
		head[x]->next=head[x];
		head[x]->prev=head[x];
		p=head[x];
		rear[x]=p;
		for(int j=0;j<7;j++)
		{
			p->next=new node(0);
			p->next->prev=p;
			p=p->next;
			head[x]->prev=p;
			p->next=head[x];
			rear[x]=p;
			
		}
				
	}
}
void ticket::show()
{
	node*p;
	for(int x=0;x<10;x++)
	{
	p=head[x];
	cout<<x+1<<" ";
	do
	{
		cout<<p->data<<" ";
		p=p->next;
	}while(p!=head[x]);
	cout<<"\n";
	}
}
void ticket::booking()
{
	int x,y,t;node*p;
	cout<<"enter total no of tickets that do u want to book"<<endl;
	cin>>t;
	while(t>0)
	{
	
		cout<<"enter row no in which do u want to book"<<endl;
		cin>>x;
		cout<<"enter seat no in that row"<<endl;
		cin>>y;
		if(x>0 && x<11 && y>0 && y<8)
		{
	
			p=head[x-1];
			for(int i=0;i<y-1;i++)
			{
				p=p->next;
			}
			p->data=1;
			t--;
		}
		else
		{
			cout<<"enter valid data"<<endl;
		}
	}
}
/*void ticket::available()
{
	node*p;
	for(int i=0;i<10;i++)
	{
		p=head[i];
		for(int j=0;j<7;j++)
		{
			
			if(p->data==0)
			{
				cout<<"seat of "<<i+1<<"  row and  "<<j+1<<"  seat no is available"<<endl;
			}
			p=p->next;
		 }
	}
	
}
void ticket::booked()
{
		node*p;
	for(int i=0;i<10;i++)
	{
		p=head[i];
		for(int j=0;j<7;j++)
		{
			
			if(p->data==1)
			{
				cout<<"seat of "<<i+1<<"  row and  "<<j+1<<"  seat no is booked"<<endl;
			}
			p=p->next;
		 }
	}
}*/
void ticket::cancelbooking()
{
	node*p;int x,y,t;
	cout<<"enter total no of seats that u want to cancel"<<endl;
	cin>>t;
	while(t>0)
	{
	
	cout<<"enter row no and seat no that do u want to cancel"<<endl;
	cin>>x>>y;
		p=head[x-1];
		for(int j=0;j<y-1;j++)
		{
		
			p=p->next;
		}
				
			if(p->data==1)
			{
				p->data=-1;
			}
			else
			{
				cout<<"this ticket is not already booked";
			}
			t--;
	}
	show();
}
/*
void ticket::show1()
{
	node*p;int flag =0;
	for(int i=0;i<10;i++)
	{
		p=head[i];
		for(int j=0;j<7;j++)
		{
				
			if(p->data==-1)
			{
				cout<<"seat no "<<j+1<<" of row "<<i+1<<" is get canceled"<<endl;
				p->data=0;
				flag=1;
			}
		
			p=p->next;
		}
	}
	if(flag==0)
	{
		cout<<"no any seat get canceled"<<endl;
	}
}*/
int main()
{
	ticket obj;int ch;
	obj.creat();
	obj.booking();
	obj.show();
	while(1)
	{
		cout<<"enter 1 for showing available seats to book"<<endl;
		cout<<"enter 2 for showing booked seats"<<endl;
		cout<<"enter 3 for cancelation of seat"<<endl;
		cout<<"enter 4 for new bookong of seat"<<endl;
		cout<<"enter 5 for exit"<<endl;
		cout<<endl<<"enter your choice"<<endl;
		cin>>ch;
		switch(ch)
		{
			case 1:obj.show();
			break;
			case 2:obj.show();
			break;
			case 3:obj.cancelbooking();
			break;
			case 4:obj.booking();
			break;
			case 5:exit(1);
		}
	}
	
}


