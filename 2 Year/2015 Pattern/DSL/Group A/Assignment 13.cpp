// Write a C++ program to realize polynomial equation and perform operations. Write function 
//  1. To input and output polynomials represented as bmxem+ bm-1xem-1+..... +b0xe0.Your functions should overload the << and >> operators.
//  2. Evaluates a polynomial at given value of x2.
//  3. Add two polynomials3.
//  4. Multiplies two polynomials

//  Author: Mohit Khedkar.

#include <iostream>
using namespace std;
class polynomial
{
	friend class term;
};
class term
{
	public:
	int ex;
	int ce;
	term()
	{
		ex=0;
		ce=0;
		sum=0;
	}

	int sum;
	void val(int);
	friend istream &operator >> (istream &in,term &p)
	{
		cout<<"Enter the coefficient and power\n";
		 in>>p.ce>>p.ex;
		 return in;
	}
	friend ostream &operator<<(ostream &out,term &p)
	{
		out<<p.ce<<"x"<<p.ex;
		return out;
	}
};

void term::val(int x)
{
	int valu=1;
	for(int i=1;i<=ex;i++)
	{
		valu=valu*x;
	}
	sum=ce*valu;
}

void print(term *p,int x)
{

	for(int i=0;i<x;i++)
	{
		if(i>0){
			cout<<"+";
		}
		cout<<p[i];

	}
}
int solveforx(term *p,int n)
{
	int plus=0;
	for(int i=0;i<n;i++)
	{
		plus=plus+p[i].sum;
	}
	return plus;
}
int addpoly(term *p1,term *p2,term *p3,int n,int m)
{
	int i=0,j=0,k=0;
	int c=0;

	while((i!=n)&&(j!=m))
	{
			if(p1[i].ex==p2[j].ex)
			{
				p3[k].ce=p1[i].ce+p2[j++].ce;
				p3[k++].ex=p1[i++].ex;
				c++;

			}
			else if(p1[i].ex>p2[j].ex)
			{
				p3[k].ce=p1[i].ce;
				p3[k++].ex=p1[i++].ex;
				c++;
			}
			else if((p1[i].ex<p2[j].ex))
			{
				p3[k].ce=p2[j].ce;
				p3[k++].ex=p2[j++].ex;
				c++;
			}

	}
	while((i!=n)||(j!=m))
	{
	if(i==n)
	{
		p3[k].ce=p2[j].ce;
		p3[k++].ex=p2[j++].ex;
		c++;
	}
	else if(j==m)
	{
		p3[k].ce=p1[i].ce;
		p3[k++].ex=p1[i++].ex;
		c++;
	}
	}
	return c;

}
int multiplypoly(term p1[],term p2[], term p3[],int n,int m)
{
  int tmp=0;
  term max;
  max.ex=0;
  term *p=new term[m*n];
  int k=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      p[k].ce=p1[i].ce*p2[j].ce;
      p[k++].ex=p1[i].ex+p2[j].ex;
    }
  }
  cout<<endl;
  k=0;
  for(int i=0;i<n*m;i++)
  {
    for(int j=i;j<n*m;j++)
    {
      if(max.ex==p[j].ex)
      {
        p3[k].ce+=p[j].ce;
      }
      if(max.ex<p[j].ex)
      {
        p3[k].ex=p[j].ex;
        p3[k].ce=p[j].ce;
        max.ex=p[j].ex;
        tmp=1;
      }
    }
    if(tmp==1)
    {
    k++;
    tmp=0;
    }
    max.ex=0;
  }
return k;
}
int main()
{
	int n,x,c;
	cout<<"Enter NO .of terms: ";
	cin>>n;
	term p1[n];
	for(int i=0;i<n;i++)
	{
		cin>>p1[i];
	}
	print(p1,n);
	cout<<"\nEnter value of x:\n";
	cin>>x;
	for(int i=0;i<n;i++)
		{
			p1[i].val(x);
		}
	cout<<solveforx(p1,n);
	cout<<endl;
	int m,y;
	cout<<"Enter NO .of terms: ";
	cin>>m;
	term p2[m];
	for(int i=0;i<m;i++)
	{
		cin>>p2[i];
	}
	print(p2,m);
	cout<<"\nEnter value of x:\n";
	cin>>y;
	for(int i=0;i<m;i++)
		{
			p2[i].val(y);
		}
	cout<<solveforx(p2,m);
	term p3[m+n];
	int count;
	cout<<"Enter:\n1.ADD\n2.Multiply\n";
	cin>>c;
	switch(c)
	{
	case 1:count=addpoly(p1,p2,p3,n,m);
	cout<<count<<endl;
	      print(p3,count);
	      break;
	case 2:count=multiplypoly(p1,p2,p3,n,m);
	       print(p3,count);
	       break;
	default:cout<<"Wrong choice!\n";
	       break;
	}

	return 0;
}