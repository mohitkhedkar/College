// Write C++ program to store second year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
//  1. Insertion sort  
//  2. Shell Sort and display top five scores

// Author: Mohit Khedkar.

#include <iostream>
#include<ctime>
#define max 10
using namespace std;

class sort {
	float* num;
	int n;
public:
	sort() {
		cout<<"no of students"<<endl;
		cin>>n;
		num=new float[n];
}
	void input();
	void output();
	void insertion();
	void shell();
};

void sort::input() {
	cout<<"enter percentage";
	for(int i=0;i<n;i++) {
		cin>>num[i];
	}
}

void sort::output() {
	cout<<"sorted array is:"<<"   ";
	for(int i=0;i<n;i++) {
			cout<<num[i]<<"  ";
		}
	cout<<endl;
}

void sort::insertion() {
	int temp;
	for(int i=1;i<n;i++) {
		temp=num[i];
		int j=i-1;
		while(num[j]>temp && j>=0) {
			num[j+1]=num[j];
			num[j]=temp;
			j=j-1;

		}
		num[j+1]=temp;
	}
}

void sort::shell() {
	int j;
	for(int gap=n/2;gap>0;gap=gap/2) {
		for(int i=gap;i<n;i++) {
			int temp=num[i];
			for( j=i;j>=gap && num[j-gap]>temp;j=j-gap) {
				num[j]=num[j-gap];

			}
			num[j]=temp;
		}
	}
}


int main() {
	int k=1;
	sort s;
	s.input();



	int choice;
	do
	{
		cout<<"1. Insertion"<<endl<<"2. Shell"<<endl;
		cout<<"Enter choice";
		cin>>choice;
		int time=clock();
		switch(choice)
		{
		case 1: s.insertion();
		       cout<<endl<<clock()-time<<endl;
		        s.output();
		        break;
		case 2:s.shell();
		       cout<<endl<<clock()-time<<endl;
		       s.output();
		       break;

		}
	}while(choice<=2);

    return 0;
}