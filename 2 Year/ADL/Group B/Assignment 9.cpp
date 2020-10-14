// Write a function to get the number of vertices in an undirected graph and its edges. You may assume thatno edge is input twice. 
// 1. Use adjacency list representation of the graph and find runtime of the function
// 2. Use adjacency matrix representation of the graph and find runtime of the function

// Author: Mohit KHedkar

#include<iostream>
#include<stdlib.h>
using namespace std;
struct node
{   char vertex;
    node *next;
};   
class adjmatlist
{    int m[10][10],n,i,j; char ch;  char v[20];   node *head[20];  node *temp=NULL;

     public:
     adjmatlist()
     {      for(i=0;i<20;i++)
            {    head[i]=NULL;  }
     }          
     void getgraph();
     void adjlist();
 
     void displaym();
     void displaya();
};
void adjmatlist::getgraph()
{
   cout<<"\n enter no. of vertices in graph(max. 20)";
   cin>>n;
   cout<<"\n enter name of vertices";
   for(i=0;i<n;i++)
     cin>>v[i];         
   for(i=0;i<n;i++)
   { 
      for(j=0;j<n;j++)
      {  cout<<"\n edge present between "<<v[i]<<"-----"<<v[j]<<" then press enter y otherwise n"; 
         cin>>ch;
         if(ch=='y')
         { m[i][j]=1;  }
         else if(ch=='n')
         {  m[i][j]=0;  }
         else
         { cout<<"\n unknown entry";  }
      }
   }       
      adjlist();
        
}
void adjmatlist::adjlist()
{     
       for(i=0;i<n;i++)
       {  node *p=new(struct node);
          p->next=NULL;
          p->vertex=v[i];   
          head[i]=p;      // cout<<"\n"<<head[i]->vertex;
       }
     
       for(i=0;i<n;i++)
       {  for(j=0;j<n;j++)
          {
                   if(m[i][j]==1)
                   {      
                         node *p=new(struct node);
                         p->vertex=v[j];
                         p->next=NULL;
                         if(head[i]->next==NULL)
                         {  head[i]->next=p;   }
                         else
                         {  temp=head[i];
                         while(temp->next!=NULL)
                         {   temp=temp->next;  }
                             temp->next=p;
                         }

                   }

          }
       }  
     
}
void adjmatlist::displaym()
{
     for(i=0;i<n;i++)
     {  for(j=0;j<n;j++)
         cout<<m[i][j]<<"  ";
         cout<<"\n";
     }
}   
void adjmatlist::displaya()
{     
       cout<<"\n adjacency list is";
     
       for(i=0;i<n;i++)
       { 
                 
             
                         if(head[i]==NULL)
                         {   cout<<"\n adjacency list not present";  break;   }
                         else
                         { 
                            cout<<"\n"<<head[i]->vertex;
                         temp=head[i]->next;
                         while(temp!=NULL)
                         {  cout<<"-> "<<temp->vertex;
                            temp=temp->next;  }
                            
                         }

                  

         
       }
     
}
int main()
{  int m;   
   adjmatlist a;

   while(1)
   {
   cout<<"\n\n enter the choice";
   cout<<"\n 1.enter graph";
   cout<<"\n 2.display adjacency matrix";
   cout<<"\n 3.display adjacency list";
   cout<<"\n 4.exit";
   cin>>m;
  
        switch(m)
       {              case 1: a.getgraph();
                                    break;
                     case 2: a.displaym();
                                   break;
                          
                           case 3: a.displaya();
                                   break;
                            case 4: exit(0);
                
                            default:  cout<<"\n unknown choice";
         }
    }
    return 0;
}           