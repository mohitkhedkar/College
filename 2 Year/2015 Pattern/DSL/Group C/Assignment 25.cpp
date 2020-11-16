// Implement C++ program for expression conversion as infix to postfix and its evaluation using   stack based on given conditions
//  1. Operands and operator, both must be single character.
//  2. Input Postfix expression must be in a desired format. 
//  3. Only '+', '-', '*' and '/ ' operators are expected.

//  Author: Mohit Khedkar.

#include <iostream>
using namespace std;
#define size 50
class job
{
	string name;
	string time;
	public:
	job()
	{
		name = "\0";
		time = "\0";
	}
	void getdata();
	void putdata();
};
void job::getdata()
{
	cout<<"Enter Job Name: ";
	cin>>name;
	cout<<"Enter Duration of Job: ";
	cin>>time;
}
void job :: putdata()
{
	cout<<"Job Name: "<<name<<endl;
	cout<<"Duration of Job: "<<time;
}
class deque
{
	job arr[size];
	int front;
	int rear;
	public:
	deque()
	{
		front =-1;
		rear =-1;
	}
	void push_front(job);
	void push_rear(job);
	job givefront();
	job giverear();
	void pop_rear();
	void pop_front();
	bool isempty();
	friend void print_data(deque);
};
void print_data(deque q)
{
	job j;
	cout<<"Job List is : "<<endl;
	if(q.isempty())
	{
		cout<<"Empty!"<<endl;
	}
	while(!q.isempty())
	{
		j = q.givefront();
		j.putdata();
		q.pop_front();
		cout<<endl;
	}
}

void deque::push_front(job j)
{
	if(front == -1)
	{
		rear=front = (size/2);
		arr[front] = j;
	}
	else if(front == 0)
	{
		cout<<"Overflow! "<<endl;
	}
	else
	{
		front = front - 1;
		arr[front] = j;
	}
}
void deque::push_rear(job j)
{
	if(rear == -1)
	{
		rear = front = (size/2);
		arr[rear] = j;
	}
	else if(rear == (size -1))
	{
		cout<<"Underflow! "<<endl;
	}
	else
	{
		rear =rear + 1;
		arr[rear] = j;
	}
}
void deque::pop_front()
{
	if((front == -1)||(front == rear+1))
	{
		cout<<"Underflow! "<<endl;
		front = rear = -1;
	}
	else
	{
		front = front + 1;
	}
}
void deque::pop_rear()
{
	if((rear == -1)||(front == rear +1))
	{
		cout<<"Underflow! "<<endl;
		front = rear = -1;
	}
	else
	{
		rear = rear -1;
	}
}
job deque::givefront()
{
	return arr[front];
}
job deque::giverear()
{
	return arr[rear];
}
bool deque::isempty()
{
	if((front == -1) || (front == rear +1))
	{
		return true;
	}
	else
	{
		return false;
	}
}

int main()
{
	deque q;
	job j;
	int t=1;
	while(t)
	{
		
		cout<<"Enter Choice:\n1.Add Front\n2.Add rear\n3.Delete Front\n4.Delete rear\n5.Display Job List\n6.Exit"<<endl;
		int choice;
		cin>>choice;
		switch(choice)
		{
		case 1:cout<<"Enter Details of Job! "<<endl;
			j.getdata();
			q.push_front(j);
			break;
		case 2:
			cout<<"Enter Details of Job! "<<endl;
			j.getdata();
			q.push_rear(j);
			break;
		case 3:
			q.pop_front();
			cout<<"Front is Poped! "<<endl;
			break;
		case 4:
			q.pop_rear();
			cout<<"Rear is Poped! "<<endl;
			break;
		case 5:
			print_data(q);
			break;
		case 6:
			t=0;
			break;
		default:
			cout<<"Wrong Choice! "<<endl;
		}
	}

	return 0;
}