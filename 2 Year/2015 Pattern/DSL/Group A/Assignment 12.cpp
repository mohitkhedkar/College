// Write C++ program for string operations-copy, concatenate, check substring, equal, reverse  and length.

// Author: Mohit Khedkar.

#include <iostream>

using namespace std;
class str
{
    char a[20],b[20],c[20],d[20],e[20],g[20],h[30];
public:
    void getdata()
    {   cout<<"enter string a"<<endl;
       cin.getline (a,20);
        cout<<"enter string b"<<endl;
        cin.getline (b,20);
    }
    void lenght()
    {   int lenght=0,fan=0;
        while(a[lenght]!='\0')
        {
            lenght++;
        }
        cout<<"length of a is "<<lenght<<endl;
        while(b[fan]!='\0')
        {
            fan++;
        }
         cout<<"length of b is "<<fan<<endl;
    }
    void concat()
    {
        cout<<"string a is:"<<a<<endl;
        cout<<"string b is:"<<b<<endl;
        cout<<"the concatination string is :"<<a<<b<<endl;
    }
    void reversestr()
    {   int i;
        char temp='\0';
        int nel=0,fan=0;
        while(a[nel]!='\0')
         {
             nel++;
         }

        for(i=0;i<nel/2;i++)
             {   temp=a[i];
                 a[i]=a[nel-i-1];
                 a[nel-i-1]=temp;
             }

        cout<<a<<endl;
        while(b[fan]!='\0')
         {
             fan++;
         }

        for(i=0;i<fan/2;i++)
             {   temp=b[i];
                 b[i]=b[fan-i-1];
                 b[fan-i-1]=temp;
             }

        cout<<b<<endl;
 }
    void strequal()
{
    int nel=0,i,count=0;
        while(a[nel]!='\0')
         {
             nel++;
         }
         int fan=0;
        while(b[fan]!='\0')
         {
             fan++;
         }
         int mux;
         mux=nel>fan?nel:fan;
         for(i=0;i<mux;i++)
         {
             if(a[nel-1-i]==b[fan-1-i])
             {
                 count++;
             }
         }
         if(count == nel)
         {
        	 cout<<"strings are equal"<<endl;
         }
         else
         {
        	cout<<"strings are not equal"<<endl;
         }
}
    void copystr()
    {
        int i,nel=0,temp=0;
        while(a[nel]!='\0')
         {
             nel++;
         }
        for(i=0;i<nel/2;i++)
         {   temp=a[i];
              a[i]=a[nel-i-1];
              a[nel-i-1]=temp;
          }
         for (i=0;i<nel;i++)
         {
             c[i]=a[i];
         }
         cout<<"the copied string is "<<c<<endl;
    }
    void substring()
    {   int i=0;
    char temp='\0';
    int nel=0,fan=0;

   while(b[fan]!='\0')
     {
         fan++;
     }

    for(i=0;i<fan/2;i++)
         {   temp=b[i];
             b[i]=b[fan-i-1];
             b[fan-i-1]=temp;
         }


    	int j=0,flag=0,x=0;
    		    	while(a[nel]!='\0')
    		        {
    		    	    nel++;
    		        }

    		    	 while(b[fan]!='\0')
    		         {
    		           fan++;
    		         }

    		    	 for( i=0;i<nel&&flag==0;i++)
    		         {
    		    		x=i;
    		    	    if(b[0]==a[x])
    		    	    { flag=1;
    		    		  for(j=1;j<fan;j++)
    		    		  { x++;
    		    		    if(b[j]!=a[x])
    		    		    {
    		    		    	flag=0;
    		    		    }

    		    		  }
    		    		}
    		    	  }


    		        if(flag==1)
    		    	{
    		    		cout<<b<<":is subtring of:" <<a<<endl;
    		    	}
    		    	else
    		    	{
    		    		cout<<"there is no sub string"<<endl;
    		    	}


    }
};

int main()
{
 str f;
    f.getdata();
    f.lenght();
    f.concat();
    f.reversestr();
    f.strequal();
    f.copystr();
    f.substring();
 return 0;
}