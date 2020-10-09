// A magazine committee is to be formed that consists of any 3 members to be selected from   { Nikhita, Aboli, Megha, Sanika, Pratik, Saurabh}. 
// Write C/C++ program to list all possible committees.

// Author : Mohit Khedkar

#include<iostream>
using namespace std;


class committee
{
 char name[6][10]={ "Nikhita", "Aboli","Megha", "Sanika", "Pratik", "Saurabh"};
public:
 void Possible_committees();    // 6*5*4=120
};

void committee::Possible_committees()
{
 for(int i=0;i<6;i++)
 {

  for(int j=0;j<6;j++)
  {
   if(i!=j)
   {
    for(int k=0;k<6;k++)
   {
     if(k!=i&&k!=j)
     {
   cout<<name[i]<<","<<name[j]<<","<<name[k]<<"\n";
     }

   }
   }
  }
 }
}
int main()
{
 committee c;
 c.Possible_committees();
}