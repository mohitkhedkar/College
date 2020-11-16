// Write C++ program to store first year percentage of students in array. Sort array of floating point numbers in ascending order using quick sort and display top five scores.

// Author: Mohit Khedkar.

#include<iostream>
using namespace std;

class student {
	char name[20];
	float per;
	public:
		
		void getinfo() {
			cout<<"enter details";
			cout<<"enter name and percentage\n";
			cin>>name;
			cin>>per;
		}
		void putinfo() {
			cout<<"\nname:  "<<name<<"   "<<"percentage:  "<<per<<endl;
		}
		friend class report;
};

class report {	
	student *s;
	
    public:
    int n;		
	report() {
		cout<<"enter no of student\n";
		cin>>n;
		s=new student[n];
	}
	void getdata();
	void putdata();
	void sort(int ,int);
	void aftersorting();
};

void report::getdata() {
	for(int i=0;i<n;i++) {
		s[i].getinfo();
	}
}

void report::putdata() {
	for(int i=0;i<n;i++) {
		s[i].putinfo();
	}
}

void report::aftersorting() {
	for(int i=0;i<n;i++) {
		cout<<s[i].per<<"  ";
	}
}

void report::sort(int low,int high) {
	int k,i,pivot,j;
	float temp;
	
	if(low>=high) {
		return;
	} else {
		pivot=low;
		i=low+1;
		j=high;
		do {
			while(s[i].per<s[pivot].per&& i<=high) {
				i++;
			}
			while(s[j].per>s[pivot].per&& j>=low) {
				j--;
			}
			if(i<j) {
			     temp=s[i].per;
				 s[i].per=s[j].per;
				 s[j].per=temp;	
			}
			i++;
			j--;
		}while(i<=j);
		temp=s[pivot].per;
		s[pivot].per=s[j].per;
		s[j].per=temp;
		sort(low,j-1);
		sort(j+1,high);
	}
}

int main() {

	report x;
	x.getdata();
	x.putdata();
    x.sort(0,x.n-1);
    cout<<"\nascending order of marks obtained by students:   ";
	x.aftersorting();
}