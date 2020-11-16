// Write C++ program to store roll numbers of student in array who attended training program in random order. Write function for-

// 1. Searchingwhether particular student attended training program or not using linear search and sentinel search.
// 2. Searchingwhether particular student attended training program or not using binary search and Fibonacci search.

// Author : Mohit Khedkar

#include <iostream>
#include<ctime>
#define max 10
using namespace std;



class search {
    public:
	int n;
	 int num[max];
		int ele;
        bool attendance;
        search() {
        		cout<<"enter size";
        		cin>>n;
        }

		void input();
		void output();
		void sort();
		void rbinarysrch(int ele,int ,int );
		void binarysrch(int ele);

};

void search::input() {
	cout<<"\nenter roll no \n";
	for(int i=0;i<n;i++) {
		cin>>num[i];
	}

}

void search::output() {
	cout<<"roll no of student:";
    for(int i=0;i<n;i++) {
				cout<<num[i]<<"  ";
			}
    cout<<endl;
}

void search::sort() {
	int temp;
	for(int i=0;i<n;i++) {
			for(int j=i+1;j<n;j++) {
				if(num[i]>num[j]) {
					temp=num[i];
					num[i]=num[j];
					num[j]=temp;

				}
			}
		}
}

void search::rbinarysrch(int ele,int low,int high) {

	int	mid =(low+high)/2;

		if(ele<num[mid]) {
			high=mid-1;
		}
		else {
			low=low+1;
		}
		if(num[mid]==ele) {
			cout<<ele<<"  found at "<<mid<<" position";
		}
		else {
			rbinarysrch(ele,low,high);
		}

}

void search::binarysrch(int ele) {
	int low,high,mid;
	low=0;
		high=4;
		mid=(low+high)/2;

		if(ele<num[mid]) {
			high=mid-1;
		}
		else {
			low=low+1;
		}
		for(int i=low;i<=high;i++) {
			if(num[i]==ele)
			{
				cout<<num[i]<<"  found at "<<i<<" position";
			}
		}

}
int main() {
	int low,high;
	search s;
	int time_required=clock();
    cout<<time_required;
	s.input();
    s.sort();

	cout<<clock()-time_required;
	s.output();
	cout<<"\nenter roll no of student to be search";
	cin>>s.ele;
    low=0;
	high=s.n-1;
    s.rbinarysrch(s.ele,low,high);
    cout<<endl;
    s.binarysrch(s.ele);
}