// You are the owner of a hardware store and need to keep an inventory that can tell you what different tools you have, how many of each you have on hand and the cost of each one. Write a program that initializes the random-access file hardware.dat to 100 empty records, lets you input the data concerning each tool, enables you to list all your tools, lets you delete a record for a tool that you no longer have and lets you update any information in the file. The tool identification number should be the record number. Use the  following information  to  start your file:
//     Record#    Tool name    Quantity    Cost
//     3       Electric sander    7        57.98
//     17      Hammer             76       11.99
//     24      Jig saw            21       11.00
//     39      Lawn mower         3        79.50
//     56      Power saw          18       99.99

// Author: Mohit KHedkar.

#include<iostream>
#include<fstream>
#include<string.h>
#define max 30
using namespace std;

class item
{
	public:

	int no;
	char name[max];
	int qty;
	float cost;


	item()
	{   no=0;
		strcpy(name," ");
		qty=0;
		cost=0;
	}
	void read();
	void display();
};


void item::read()
{
	cout<<"\nEnter item no: ";
	cin>>no;
	cout<<"\nEnter Name: ";
	cin>>name;
	cout<<"\nEnter Quantity: ";
	cin>>qty;
	cout<<"\nEnter Cost: ";
	cin>>cost;

}

void item::display()
{
	{
		cout<<"\nItem number:"<<no;
		cout<<"\nName:"<<name;
		cout<<"\nQuantity:"<<qty;
		cout<<"\nCost:"<<cost<<endl;
	}
}

int main()
{
	fstream file;
	item obj;

	int choice;
	do
	{
	cout<<"****************MENU******************";
	cout<<"\n1.Create new file:\n2.Add record:\n3.Display\n4.Modify\n5.Delete";
	cout<<"\nEnter your choice:\n";
	cin>>choice;
	switch(choice)
	{
		case 1:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate |ios::trunc);
			for(int i=0;i<100;i++)
				file.write((char *)&obj, sizeof(obj));

			file.close();
			cout<<"\nNEW FILE SUCCESSFULLY CREATED\n";
			break;
		case 2:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			obj.read();

			int wloc;
			wloc= (obj.no-1)*sizeof(obj);
			if(file.eof())
				file.clear();

			file.seekp(wloc);


			file.write((char *)&obj, sizeof(obj));
			file.close();
			break;
		case 3:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			file.seekg(0,ios::beg);

			while(file.read((char *)&obj, sizeof(obj)))
			{
			     if(obj.no!=0)
				     obj.display();
			}
			file.close();
			break;
		case 4:
	     		file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			cout<<"\nEnter item no to be modified: ";
			int n;
			cin>>n;

			int loc;
			loc= (n-1)*sizeof(obj);
			if(file.eof())
				file.clear();

			file.seekp(loc);

			cout<<"\nENTER NEW DATA ";
			obj.read();

			file.write((char *)&obj, sizeof(obj));
			
			file.close();
			break;
		case 5:
			file.open("item.dat",ios::binary |ios::in |ios::out | ios::ate);
			cout<<"\nEnter item no to be deleted:";
			int d;
			cin>>d;

			int dloc;
			dloc= (d-1)*sizeof(obj);
			if(file.eof())
				file.clear();

			file.seekp(dloc);

			obj.no=0;
			strcpy(obj.name , " ");
			obj.qty=0;
			obj.cost=0;
			file.write((char *)&obj, sizeof(obj));
			file.close();

			break;
	}
	}while(choice<6);

	return 0;
}