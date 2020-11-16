// Write C++ program with class for String. Write a function
//  1. frequency that  determines  the  frequency  of  occurrence  of  particular  character  in  the string. 
//  2. delete that accepts two integers, startand length. The function computes a new string that is equivalent to the original string, except that lengthcharacters being at starthave been removed.
//  3. chardelete that accepts a character c. The function returns the string with all occurrences of cremoved.
//  4. replaceto make an in-place replacement of a substring wof a string by the string x. note that wmay not be of same size of x
//  5. palindrometo check whether given string is palindrome or not

// Author: Mohit Khedkar.

#include <iostream>
using namespace std;

class str {
        char a[20],b[20],c[20],d[20],e[20],g[20],h[30];
    public:
        void getdata()
        {   cout<<"enter string a"<<endl;
            cin.getline (a,20);
            cout<<"enter string b"<<endl;
            cin.getline (b,20);
        }

    void frequency() {
        cout<<"enter a character to find its frequency"<<endl;
        char h;
        cin>>h;
        int temp=0,i=0;
        while(a[i]!='\0')
        {
            if( a[i]==h)
            {	temp++;
            }
            i++;
        }
        cout<<"its frequency is:"<<temp<<endl;
    }

    void delete1() {
            int n,m;
            cout<<"enter the index to start delete"<<endl<<"enter the no. characters to delete"<<endl;
            cin>>m>>n;
            int i,k,j=0,nel=0;
                    while(a[nel]!='\0')
                    {
                        nel++;
                    }
                    for (i=0;i<nel;i++)
                            {
                                d[i]=a[i];
                            }
                        d[nel]='\0';
                    while(d[j]!='\0')
                    {
                        for(k=m;k<(m+n);k++)
                        {
                            d[k]= ' ';
                        }
                        j++;

                    }
                    cout<<d<<endl;

    }

    void delete2() {
            int i,j=0,nel=0;
            while(a[nel]!='\0')
            {
            nel++;
            }
            for (i=0;i<nel;i++)
                {
                    e[i]=a[i];
                }
            e[nel]='\0';
            char h;
            cout<<"enter the char. whose occurance is to be removed from string a"<<endl;
            cin>>h;
            while(e[j]!='\0')
            {
                if(e[j]==h)
                {
                    e[j]=' ';
                }
                j++;
            }
            cout<<e<<endl;


    }

    void replace()
    {
            int i=0;
            // char temp='\0';
            int nel=0,fan=0;

                        int j=0,flag=0,x=0,p=0,q=0;
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
                                    p=i;
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
                        cout<<"enter the substring viz to be replaced with" <<endl;
                        //  char g[20],h[30];
                        cin.getline (g,20);
                        int k=0,l=0,m=0,n=0;
                        while(g[m]!='\0')
                        {
                            m++;
                        }
                        for(k=0;k<p;k++)
                        {
                            h[k]=a[k];
                        }
                        for(k=p;k<(p+m);k++)
                        {
                            h[k]=g[l];
                            l++;
                        }
                        
                        k=(p+m);
                        n=(p+fan);
                        while(a[n] != '\0')
                        {
                            h[k]=a[n];
                            k++;
                            n++;
                        }
                        h[(p+m+(nel-(p+fan)))]='\0';

                        cout<<h<<endl;

    }

    void palindrome() {
            int i=0,nel=0,temp=0;
            while(a[nel]!='\0')
            {
            nel++;
            }

            while(a[i]!='\0')
            {
                if( a[i]==a[nel-1-i])
                {	temp++;
                }

                i++;
            }
            if(temp == nel)
            {
                cout<<a<<" : is a palindrome"<<endl;
            }
            else
            {
                cout<<a<<" : is not a palindrome"<<endl;
            }

    }
};

int main() {
 str s;
    s.getdata();
    s.replace();
    s.delete1();
    s.delete2();
    s.palindrome();
    s.frequency();

    return 0;
}