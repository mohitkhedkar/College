// In any language program mostly syntax error occurs due to unbalancing delimiter such as (),{},[].    Write  C++  program  using  stack  to  check  whether  given  expression  is  well parenthesized or not. 

// Author : Mohit Khedkar.

#include <iostream>
#include<string>
using namespace std;
class stack;
class node
{
	char ch;
	node* prev;
	public:
	node()
	{
		ch='\n';
		prev = NULL;
	}
	friend class stack;
};
class stack
{
	node* top;
	public:
	stack()
	{
		top = NULL;
	}
	void push(char);
	void pop();
	char givetop();
	bool isempty();
};
char stack::givetop()
{
	return top->ch;
}
void stack::push(char ch)
{
	if(top == NULL)
	{
		top=new node;
		top->ch=ch;
	}
	else
	{
		node* tmp = new node;
		tmp->ch=ch;
		tmp->prev=top;
		top = tmp;
	//	tmp=NULL;
	}
}
void stack::pop()
{
	if(top==NULL)
	{
		cout<<"stack is Empty! ";
	}
	else if(top->prev == NULL)
	{
		delete top;
		top=NULL;
	}
	else
	{
		node* tmp;
		tmp=top;
		top=top->prev;
		tmp->prev=NULL;
		delete tmp;
		tmp=NULL;
	}
}
bool stack::isempty()
{
	if(top==NULL)
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
	stack s;
	int tmp=0;
	string str;
	cout<<"Enter equation :"<<endl;
	cin>>str;
	for(int i=0;i<str.length();i++)
	{
		switch(str[i])
		{
		case '{': s.push('{');
		break;
		case '(': s.push('(');
		break;
		case '[': s.push('[');
		break;
		case '}':
		if(s.isempty() == true)
		{
			i=str.length();
			tmp=1;
		}
		else
		{
			if(s.givetop() == '{')
			{
				s.pop();
			}
		}
		break;
		case ')':
		if(s.isempty() == true)
		{
			i=str.length();
			tmp=1;
		}
		else
		{
			if(s.givetop() == '(')
			{
				s.pop();
			}
		}
		break;
		case ']':
		if(s.isempty() == true)
		{
			i=str.length();
			tmp=1;
		}
		else
		{
			if(s.givetop() == '[')
			{
				s.pop();
			}
		}
		break;
		default:{}
		}
	}
	if(tmp==0 && s.isempty() == true)
	{
		cout<<"Correct Equation"<<endl;
	}
	else
	{
		cout<<"Wrong Equation"<<endl;
	}

	return 0;
}