// Write C/C++ program for storing matrix. Write functions for
//  1. Check whether given matrix is upper triangular or not
//  2. Compute summation of diagonal elements
//  3. Compute transpose of matrix
//  4. Add, subtract and multiply two matrices 

// Author: Mohit Khedkar

#include<iostream>
using namespace std;
void diagonal(int[3][3]);
void triangular(int[3][3]);
void transpose(int[3][3]);
void arithmatic(int[3][3]);


int main()
{  int mat[3][3], choice;
   cout<<"\nEnter the elements in matrix";
   for(int i=0;i<3;i++)
   {
        for(int j=0;j<3;j++)
        {
             cin>>mat[i][j];
             
        }
       
   }
   for(int i=0;i<3;i++)
   {
        for(int j=0;j<3;j++)
        {
             cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
   }
   cout<<"\nMENU\n 1) To check for diagonal elements \n 2) To check for upper triangular matrix \n 3) Transpose \n 4) Arithmatic operations\n";
   cin>>choice;
   switch(choice)
   {
       case 1 :diagonal(mat);
              break;
       case 2 :triangular(mat);
              break;
       case 3 :transpose(mat);
              break;
       case 4 :arithmatic(mat);
              break;  
      
              
       default : cout<<"\nEnter the valid option!!!"; 
              break;           
   }
   return 0;
}




void diagonal(int mat[3][3])
{  int a=0;
  for(int i=0;i<3;i++)
   {
        for(int j=0;j<3;j++)
        {
             if(i==j&&mat[i][j]==0)
             { 
               a++;  
                
             }
        }
   }
   if(a==3){
   cout<<"\nIt is a diagonal matrix";}
   else
   cout<<"\nIt is not a diagonal matrix";
}




void triangular(int mat[3][3])
{int b=0;
for(int i=0;i<3;i++)
   {
        for(int j=0;j<3;j++)
        {
             if(i>j&&mat[i][j]==0)
             {
                b++;
             }
        }
   }
   if(b==3)
   {cout<<"\nIt is an upper triangular matrix\n";
   }
   else
   cout<<"It is not an upper traingular matrix";
}




void transpose(int mat[3][3])
{for(int j=0;j<3;j++)
   {
        for(int i=0;i<3;i++)
        {
             cout<<mat[i][j]<<"\t";
        }
        cout<<"\n";
   }

}




void arithmatic(int mat[3][3])
{ int art[3][3],choice, mut[3][3],sum[3][3],sub[3][3];
 
cout<<"\nEnter the values in another matrix\n";
 for(int k=0;k<3;k++)
   {
        for(int l=0;l<3;l++)
        {
             cin>>art[k][l];
             cout<<"  ";
             
        }
       
   }
   
   cout<<"1)Addition \n 2) Subtraction \n 3) Multiplication";
   cout<<"\nChoose the operation you want to perform : ";
   cin>>choice;
   switch(choice)
   {
   	    case 1 : for(int i=0;i<3;i++)
                 {
                 for(int j=0;j<3;j++)
                 {
                       sum[i][j]=mat[i][j]+art[i][j];
             
                 }
       
                 }
                 for(int i=0;i<3;i++)
                 {
                 for(int j=0;j<3;j++)
                 {
                      cout<<sum[i][j]<<"\t";
                 }
                 cout<<"\n";
                 }
   	  	    break;
	    case 2 :for(int i=0;i<3;i++)
                 {
                 for(int j=0;j<3;j++)
                 {
                       sub[i][j]=mat[i][j]-art[i][j];
             
                 }
       
                 }
                 for(int i=0;i<3;i++)
                 {
                 for(int j=0;j<3;j++)
                 {
                      cout<<sub[i][j]<<"\t";
                 }
                 cout<<"\n";
                 }
   	  	    break;  
		case 3 :for(int i=0;i<3;i++)
                {
                for(int j=0;j<3;j++)
                {
                    mut[i][j]=0;
                }
				}
	            
				for(int k=0;k<3;k++){
		        for(int l=0;l<3;l++){
		        for(int a=0;a<3;a++){
			     	 mut[k][l]=mut[k][l]+(mat[l][a]*art[a][k]);
				}
		        }
	            }
	           
			    for(int i=0;i<3;i++)
                {
                for(int j=0;j<3;j++)
                {
                    cout<<mut[j][i]<<"\t";
                }
                     cout<<"\n";
                }
   	  	    break;    
   	  	default : cout<<"\nEnter the valid option!!!";
   	  	break;
   }
   
    
}
