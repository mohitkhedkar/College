// Second year Computer Engineering class, set A of students like Vanilla Ice-cream and set B of students like butterscotch ice-cream. Write C/C++ program to store two sets using linked list. compute and display-
//  1. Set of students who like either vanilla or  butterscotch or both
//  2. Set of students who like  both vanilla and  butterscotch
//  3. Set of students who like  only vanilla not butterscotch
//  4. Set of students who like only butterscotch not vanilla
//  5. Number of students who like neither vanilla nor butterscotch

// Author: Mohit Khedkar

#include<iostream>
using namespace std;
struct node{
 
     int rollno;
     struct node*next;
};

class setAB{
      public:  node*head1=NULL;
                   node*head2=NULL;
                   node*head3=NULL;
                    node*head4=NULL;
                   
                  void add3()
                   {
                           node *temp=new node;
                       
                           node  *t; 
                       
                          cout<<"\nINSERT THE ROLL NO. OF ALL THE STUDENTS IN COMPUTER DIV. : ";
                         
                          cin>> temp->rollno;
                          temp->next=NULL;
                          if(head3==NULL)
                          {
                             head3=temp;
                          }
                          else     
                          {            t = head3;
                                       while(t->next!=NULL)
                                         {  
                                         t=t->next;
                                         }
                             t->next=temp;
                          }
                          
                     }
                     
                   void add1()
                   {
                           node *temp=new node;
                       
                           node  *t; 
                       
                          
                          cout<<"\nENTER THE ROLL NO. OF STUDENTS WHO LIKE VANILLA : ";
                          cin>> temp->rollno;
                          temp->next=NULL;
                          if(head1==NULL)
                          {
                             head1=temp;
                          }
                          else     
                          {  t = head1;
                                       while(t->next!=NULL)
                                         {  
                                         t=t->next;
                                         }
                             t->next=temp;
                          }
                          
                     }
                     void add2()
                   {
                           node *temp=new node;
                       
                           node  *t; 
                       
                          
                          cout<<"\nENTER THE ROLL NO. OF STUDENTS WHO LIKE BUTTERSCOTCH : ";
                          cin>> temp->rollno;
                          temp->next=NULL;
                          if(head2==NULL)
                          {
                             head2=temp;
                          }
                          else     
                          {  t = head2;
                                       while(t->next!=NULL)
                                         {  
                                         t=t->next;
                                         }
                             t->next=temp;
                          }
                          
                     }
                   
                   void display1()
                   {        node*display=head1; 
                       
                           cout<<"\nROLL NOS. WHO LIKE VAANILLA :  ";
                        
                           while(display!=NULL)
                            {
                            
                            cout<<display->rollno<<" ";
                            display=display->next;
                            } 
                   }
                   
                   
                   void display2()
                   {        node*display=head2; 
                       
                           cout<<"\nROLL NOS. WHO LIKE BUTTERSCOTCH :  ";
                        
                           while(display!=NULL)
                            {
                            
                            cout<<display->rollno<<" ";
                            display=display->next;
                            } 
                   }
                   
                   void intersection()
                   {
                       node* i1=head1;
                       node* i2=head2;
                       cout<<"\nROLL NOS. WHO LIKE BOTH : ";
                       while(i1!=NULL)
                       {
                            while(i2!=NULL)
                            {
                                 if(i1->rollno==i2->rollno)
                                 {
                                  cout<<i1->rollno<<"  ";
                                 }
                                 i2=i2->next;
                            }
                            i2=head2;
                            i1=i1->next;
                       }
                      
                   }
                   
                   void uunion()
                   {  
                          int flag=0;
                          node*uun1=head1;
                           node*uun2=head2;
                           cout<<"\nROLL NOS. WHO LIKE EITHER VANILLA OR BUTTERSCOTCH OR BOTH : ";
                           while(uun1!=NULL)
                           {
                                cout<<uun1->rollno<<"  ";
                                uun1=uun1->next;
                           }
                           uun1=head1;
                            while(uun2!=NULL)
                           {
                                while(uun1!=NULL)
                                {
                                     if(uun2->rollno==uun1->rollno)
                                     {
                                         flag++;
                                     }
                                     uun1=uun1->next;
                                }
                                if(flag==0)
                                {   
                                   
                                  cout<<uun2->rollno;
                                }
                                flag=0;
                                uun1=head1;
                                uun2=uun2->next;
                                
                            }
                   }
                   
                   
                   void uunion_comp()
                   {
                   	     int flag=0,flag1=0;
                   	     node*com1=head1;
                   	     node*com2=head2;
                   	     node*com3=head3;
                   	     
                   	     cout<<"\nROLL NOS. NITHER EATING VANILLA NOR BUTTERSCOTCH : ";
                   	
                   	  while(com3!=NULL)
                   	  {
                   	  	   while(com1!=NULL)
                   	  	   {
                   	  	   	
                   	  	   	if(com1->rollno==com3->rollno)
                   	  	   	{
							   flag++;
							}
                   	  	   	
                   	  	   	com1=com1->next;
						   }
						   com1=head1;
						   
						   while(com2!=NULL)
						   {
						   	if(com2->rollno==com3->rollno)
						   	{
						   		flag1++;
							}
							com2=com2->next;
						   }
						   com2=head2;
						   if(flag==0&&flag1==0)
						   {
						   	cout<<com3->rollno<<" ";
						   }
						   flag=0;
						   flag1=0;
						   
						   com3=com3->next;
						   
                   	  	
					  }
                          
                   
                   }
                   
                   
                   
                   void onlyhead1()
                   {       int flag=0;
                           node*on1=head1;
                           node*on2=head2;
                           cout<<"\nROLL NOS. WHO LIKE ONLY VANILLA  : ";
                           while(on1!=NULL)
                           {
                                while(on2!=NULL)
                                {
                                     if(on1->rollno==on2->rollno)
                                     {
                                         flag++;
                                     }
                                     on2=on2->next;
                                }
                                if(flag==0)
                                {
                                   cout<<on1->rollno<<"  ";
                                }
                                flag=0;
                                on2=head2;
                                on1=on1->next;
                             
                           }
                   
                   
                   }
                     void onlyhead2()
                   {       int flag=0;
                           node*on1=head1;
                           node*on2=head2;
                           cout<<"\nROLL NOS WHO LIKE ONLY BUTTERSCOTCH : ";
                           while(on2!=NULL)
                           {
                                while(on1!=NULL)
                                {
                                     if(on2->rollno==on1->rollno)
                                     {
                                         flag++;
                                     }
                                     on1=on1->next;
                                }
                                if(flag==0)
                                {
                                   cout<<on2->rollno<<"  ";
                                }
                                flag=0;
                                on1=head1;
                                on2=on2->next;
                             
                           }
                   
                   
                   }

};



int main()
{
       setAB ab;
       int i=0,ch,flag=0;
       
       
     do{ 
         cout<<"\n 0)INSERT THE NUMBER OF ALL THE SYUDENTS IN DIVISION \n 1)INSERT ROLL NO WHO LIKE VANILLA \n 2)INSERT ROLL NO. WHO LIKE BUTTERSCOTCH \n 3)DISPLAY VANILLA LIKING NOS. \n 4)DISPLAY BUTTERSCOTCH LIKING NOS. \n 5)DISPLAY NOS. LIKING ONLY VANILLA 1\n 6)DISPLAY NOS LIKING ONLY BUTTERSCOTCH \n 7)DISPLAY NOS. WHO LIKE BOTH \n 8)DISPALY EITHER VANILLA OR BUTTERSCOTCH OR BOTH\n 9)DISPLAY NEITHER VANILLA NOR BUTTERSCOTCH \n 10)EXIT\n";
           cin>>ch;
                switch(ch)
                {case 0 :  ab.add3();
                    break;
                 case 1 :  ab.add1();
                    break;
                case 2 :  ab.add2();
                    break;
                case 3 : ab.display1();
                    break;
                case 4 : ab.display2();
                    break;
               case 5 : ab.onlyhead1();
                    break;
                case 6 : ab.onlyhead2();
                    break;
                case 7 : ab.intersection();
                    break;
                case 8 : ab.uunion();
                    break;
                case 9 : ab.uunion_comp();
                    break;
                case 10 : cout<<"\nThans for using our console    :)\n";
                             flag=1;
                     break;
                }
                
              
              
      }while(flag!=1);
      
      
}
