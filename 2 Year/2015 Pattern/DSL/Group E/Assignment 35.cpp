// Write C++ program to store first year percentage of students in array. Write function for sorting array of floating point numbers in ascending order using
//  1. Selection Sort 
//  2. Bubble sort and display top five scores.

//  Author: Mohit Khedkar.

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
	void bubble();
	void selection();
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

void sort::bubble() {
	int temp;
	for(int i=1;i<n;i++) {
		for(int j=i-1;j<n-1;j++) {
			if(num[j]>num[j+1]) {
				temp=num[j];
				num[j]=num[j+1];
				num[j+1]=temp;
			}
		}
	}
}

void sort::selection() {
	int temp;
	for(int i=0;i<n;i++) {
		for(int j=i+1;j<n;j++) {
			if(num[i]>num[j]) {
				swap(num[i],num[j]);
			}
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
		cout<<"1. Bubble"<<endl<<"2. Selection"<<endl;
		cout<<"enter choice";
		cin>>choice;
		int time=clock();
		switch(choice)
		{
		case 1:s.bubble();
		       cout<<endl<<clock()-time<<endl;
		       s.output();
		       break;
		case 2: s.selection();
		       cout<<endl<<clock()-time<<endl;
		        s.output();
				break;
		
		}
	}while(choice<=2);

    return 0;
}