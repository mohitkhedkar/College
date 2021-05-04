// Write a program for error detection and correction for 7/8 bits ASCII codes using Hamming Codes or CRC. Demonstrate the packets captured traces using Wireshark Packet Analyzer Tool for peer to peer mode. (Use C/C++)

// using CRC

// Author: Mohit Khedkar.

#include <iostream>
using namespace std;
int main()
{
    int i,j,k,l;
     
    //Get Frame
    int fs;										//fs stores the frame size(data size) i.e. number of bits of data
    cout<<"\n Enter Size of data: ";
    cin>>fs;									
     
    int f[20];									//f[] stores the actual data of size fs-bits in binary format
    cout<<" Enter data:";						
    for(i=0;i<fs;i++)							
    {
        cin>>f[i];								//Taking input of f[] from user 1-bit at a time
    }
 
    //Get Generator
    int gs;										//gs stores the size of the generator polynomial(key size)
    cout<<"\n Enter key size: ";		
    cin>>gs;
     
    int g[20];								//g[] stores the actual value of generator polynomial in binary form
    cout<<"\n Enter key:";
    for(i=0;i<gs;i++)
    {
        cin>>g[i];								//Taking input of g[] from user 1-bit at a time 
    }
 
    cout<<"\n Sender Side:";					
    cout<<"\n data: ";
    for(i=0;i<fs;i++)							//Displaying data(frame) taken as input from user
    {
        cout<<f[i];
    }
    cout<<"\n key :";
    for(i=0;i<gs;i++)							//Displaying generator polynomial taken as input from user
    {
        cout<<g[i];
    }
 
    //Append 0's
    int rs=gs-1;								//rs stores the number of 0s to be appended to the data f[] 
    											//value of rs = size of generator polynomial (gs) - 1
    cout<<"\n Number of 0's to be appended: "<<rs;
    for (i=fs;i<fs+rs;i++)						//starting from position i=fs to fs+rs of f[], append 0s
    {
        f[i]=0;									//appending 0 at position i of f[] 
    }
 
    int temp[20];								//temp[] stores a copy of data f[] (updated with appended 0s)   
    for(i=0;i<20;i++)
    {
        temp[i]=f[i];
    }
 
    cout<<"\n Message after appending 0's :";	
    for(i=0; i<fs+rs;i++)						//Displaying the contents of temp[]
    {
        cout<<temp[i];
    }
 
    //Division
    for(i=0;i<fs;i++)							//Performing division operation - dividing temp[] by g[]
    {
        j=0;									
        k=i;
        
        //check whether it is divisible or not
        if (temp[k]>=g[j])						//Perform division only if temp[k]>=g[j]
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))	//Performing XOR operation
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    //CRC
    int crc[15];							//crc[] stores the final remainder of the above division
    for(i=0,j=fs;i<rs;i++,j++)
    {
        crc[i]=temp[j];						//inserting the remainder bits of temp[] into crc[] 
    }
 
    cout<<"\n CRC bits: ";
    for(i=0;i<rs;i++)						//displaying the crc[] bits
    {
        cout<<crc[i];
    }
 
    cout<<"\n Transmitted Frame: ";
    int tf[15];								//tf[] stores the frame to be transmitted
    for(i=0;i<fs;i++)						//copying the f[] bits taken as input from user into tf[] 
    {
        tf[i]=f[i];
    }
    for(i=fs,j=0;i<fs+rs;i++,j++)			//appending the crc[] bits to tf[]
    {
        tf[i]=crc[j];
    }
    for(i=0;i<fs+rs;i++)					//displaying tf[] i.e. the frame to be transmitted
    {
        cout<<tf[i];
    }
 
    cout<<"\n Receiver side : ";
    cout<<"\n Received Frame: ";
    for(i=0;i<fs+rs;i++)					//displaying tf[] i.e. the frame received from sender 
    {
        cout<<tf[i];
    }
 
    for(i=0;i<fs+rs;i++)					//copying tf[] into temp[]
    {
        temp[i]=tf[i];
    }
 
    //Division
    for(i=0;i<fs+rs;i++)					//Performing the same division operation as above
    {
        j=0;
        k=i;
        if (temp[k]>=g[j])
        {
            for(j=0,k=i;j<gs;j++,k++)
            {
                if((temp[k]==1 && g[j]==1) || (temp[k]==0 && g[j]==0))	//Performing XOR operation
                {
                    temp[k]=0;
                }
                else
                {
                    temp[k]=1;
                }
            }
        }
    }
 
    cout<<"\n Remainder: ";							
    int rrem[15];								//rrem[] stores the final remainder of the above division 
    for (i=fs,j=0;i<fs+rs;i++,j++)
    {
        rrem[j]= temp[i];
    }
    for(i=0;i<rs;i++)							//Displaying the remainder rrem[]
    {
        cout<<rrem[i];
    }
 
    int flag=0;									
    for(i=0;i<rs;i++)
    {
        if(rrem[i]!=0)							//if remainder rrem[] is 0, flag=0 else flag=1
        {
            flag=1;
        }
    }
 
    if(flag==0)
    {
        cout<<"\n Since Remainder Is 0 Hence Message Transmitted From Sender To Receiver Is Correct";
    }
    else
    {
        cout<<"\n Since Remainder Is Not 0 Hence Message Transmitted From Sender To Receiver Contains Error";
    }
return 0;
}
/*
OUTPUT:
student@student-OptiPlex-380:~$ g++ crc.cpp
student@student-OptiPlex-380:~$ ./a.out

 Enter Size of data: 6
 Enter data:1
0
0
1
0
0

 Enter key size: 4

 Enter key:1
1
0
1

 Sender Side:
 data: 100100
 key :1101
 Number of 0's to be appended: 3
 Message after appending 0's :100100000
 CRC bits: 001
 Transmitted Frame: 100100001
 Receiver side :
 Received Frame: 100100001
 Reaminder: 000
 Since Remainder Is 0 Hence Message Transmitted From Sender To Receriver Is Correctstudent@student-OptiPlex-380:~$
*/
