// Department library has N books. Write C/C++ program to store the cost of books in array in ascending order.  Books are to be arranged in descending order of their cost. Write function for
//  1. Reverse the contentsof array without using temporary array.  
//  2. Copy costs of books those with cost less than 500 in new array 
//  3. Delete the duplicate entries using temporary array 
//  4. Delete duplicate entries without using temporary array
//  5. Count number of books with cost more than 500.

// Author: Mohit Khedkar.

#include<iostream>
#include<string.h>
using namespace std;

struct book {
 char name[10];
 int id;
 float cost;

};

class library {
    book *s, *glessfivehundred,*temparray;
    int n;
    public :
        void getdata();
        void reverse();
        void lessfivehundred();
        void deleteduplicatetemp();
        void deleteduplicatenotemp();
        void nosofbooksmorefivehundred();
        void descendingorder();
        void display();
};

void library::getdata() {
 cout<<"\nEnter the number of books you want to enter:-";
 cin>>n;
 s=new book[n];
 for(int i=0;i<n;i++) {
  cout<<"\nBook "<<i+1;
  cout<<"\nEnter name:-";
  cin>>s[i].name;
  cout<<"\nEnter Id:-";
  cin>>s[i].id;
  cout<<"\nEnter cost:-";
  cin>>s[i].cost;
 }

}
void library::descendingorder() {
 for(int i=0;i<n;i++)  {
  for(int j=1;j<n-i;j++) {
   if(s[j-1].cost<s[j].cost) {
    char tempname[10];
    int  tempid;
    int tempcost;
    strcpy(tempname,s[j-1].name);
    tempid=s[j-1].id;
    tempcost=s[j-1].cost;
    strcpy(s[j-1].name,s[j].name);
    s[j-1].id=s[j].id;
    s[j-1].cost=s[j].cost;
    strcpy(s[j].name,tempname);
    s[j].id=tempid;
    s[j].cost=tempcost;
   }
  }
 }
}

void library::reverse() {
 for(int i=0;i<n/2;i++) {
  if(i!=n/2) {
   char tempname[10];
   int  tempid;
   int tempcost;
   strcpy(tempname,s[i].name);
   tempid=s[i].id;
   tempcost=s[i].cost;
   strcpy(s[i].name,s[n-i-1].name);
   s[i].id=s[n-i-1].id;
   s[i].cost=s[n-i-1].cost;
   strcpy(s[n-i-1].name,tempname);
   s[n-i-1].id=tempid;
   s[n-i-1].cost=tempcost;
  }
 }
}

void library::lessfivehundred(){ 
 glessfivehundred=new book[n];
 int j=0,i;
 for(i=0;i<n;i++) {
    if(s[i].cost<500) {
        strcpy(glessfivehundred[j].name,s[i].name);
        glessfivehundred[j].id=s[i].id;
        glessfivehundred[j].cost=s[i].cost;
        j++;
    }
  }
 cout<<"\nBooks having cost less than five hundred are:-";
 for(i=0;i<j;i++) {
   if(glessfivehundred[i].id!=0) {
    cout<<"\nName:"<<glessfivehundred[i].name;
    cout<<"\nId:-"<<glessfivehundred[i].id;
    cout<<"\nCost:-"<<glessfivehundred[i].cost;
   }
  }
}

void library::deleteduplicatetemp() {
 temparray=new book[n];
 int k=0,l=0;
 for(int i=0;i<n;i++) {
  k=0;
   for(int j=i+1;j<n;j++) {
         if(s[i].id==s[j].id) {
          k=1;
      }
   }
   
   if(k==0) {
        strcpy(temparray[l].name,s[i].name);
        temparray[l].id=s[i].id;
        temparray[l].cost=s[i].cost;
        l++;
    }
   }
 delete(s);
 s=temparray;

}

void library::deleteduplicatenotemp() {
   for(int i=0;i<n;i++) {
    for(int j=i+1;j<n;j++) {
     if(s[i].id==s[j].id) {
      s[j].id=0;

     }
    }
   }
}

void library::nosofbooksmorefivehundred() {
 cout<<"\nBooks having cost greater than 500 are:-";
 for(int i=0;i<n;i++) {
  if(s[i].cost>500&&s[i].id!=0) {
   cout<<"\nName:"<<s[i].name;
   cout<<"\nId:-"<<s[i].id;
   cout<<"\nCost:-"<<s[i].cost;
  }
 }
}

void library:: display() {
 cout<<"\nBooks are:-";
 for(int i=0;i<n;i++) {
   if(s[i].id!=0) {
    cout<<"\nName:"<<s[i].name;
    cout<<"\nId:-"<<s[i].id;
    cout<<"\nCost:-"<<s[i].cost;
   }
  }
}

int main() {
 library lib;
 lib.getdata();
 int n;
 lib.descendingorder();
 lib.display();
 cout<<"\n1) Reverse the contents of array without using temporary array.   \n2) Copy costs of books those with cost less than 500 in new array  \n3) Delete the duplicate entries using temporary array  \n4) Delete duplicate entries without using temporary array\n 5) Count number of books with cost more than 500\nYour choice:-";
 cin>>n;

 switch(n) {
    case 1:
    lib.reverse();
    lib.display();
    break;
    case 2:
    lib.lessfivehundred();

    break;
    case 3:
    lib.deleteduplicatetemp();
    lib.display();
    break;
    case 4:
    lib.deleteduplicatenotemp();
    lib.display();
    break;
    case 5:
    lib.nosofbooksmorefivehundred();
    break;
 }
 return 0;
}
