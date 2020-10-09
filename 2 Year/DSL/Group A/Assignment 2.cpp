// Write C/C++ program to store marks scored for first test of subject 'Data Structures and Algorithms' for N students. Compute 
//  1. The average score of class
//  2. Highest score and lowest score of class
//  3. Marks scored by most of the students
// //  4. list of students who were absent for the test

// Author : Mohit Khedkar

#include<iostream>
using namespace std;

int T[10];

void avgmarks();
void highmarks();
void lowmarks();
void Absent();
void Mostmarks();

int main()
{
  int i;
  
  cout<<"\n\t Enter Marks of 10 students: " ;


 
 for(i=0; i<10; i++)
  {
     cin>>T[i];
  }
  avgmarks();
  highmarks();
  lowmarks();
  Absent();
  Mostmarks(); 
  
  cout<<"\n\n";
  
  return 0;
}



void avgmarks()
{
   int i, total;
   float avg;
   
   total = avg = 0;
   
   for(i=0; i<10; i++)
   {
     total = total + T[i];
   }
    avg = total/10;
    cout<<"\n\t The Average Marks= "<<avg;
}


  void highmarks()
  {
   int i,Max;
   
   Max = 0;
   for(i=0; i<10; i++)
   {
     if(Max < T[i])
        Max = T[i];
   }
   cout<<"\n\t The Highest Marks= "<<Max;
  }


void lowmarks()
{
   int i,Min;
   
   Min = 999;
   for(i=0; i<10; i++)
   {
     if(Min > T[i] && T[i] != 0)
        Min = T[i];
   }
   
   cout<<"\n\t The Lowest Marks= "<<Min;
}



void Absent()
{
   int i,Abs;
   
   Abs = 0;
   for(i=0; i<10; i++)
   {
     if(T[i] == 0)
        Abs++;
   }
   
   cout<<"\n\t The Number of Absent Students= "<<Abs;
}


void Mostmarks()
{
   int i,j,k,val,Max;
   int cnt[10];
   
   for(i=0; i<10; i++)
   {
     cnt[i] = 0;
   }
   
   val = j = 0;
   
   for(i=0; i<10; i++)
   {
      val = T[i];
      j   = i;
      for(k=0; k<10; k++)
      {
         if(val == T[k])
           cnt[j]++;
      }
   }
   
   Max = 0;
   for(i=0; i<10; i++)
   {
     if(Max < cnt[i])
        Max = i;
   }
    cout<<"\n\t Marks scored by Most of Students = "<<T[Max];
}
   