//---CLIENT SIDE----
#include<sys/types.h>
#include<sys/socket.h> 
#include<stdio.h>
#include<netinet/in.h> 
#include <unistd.h>
#include<string.h> 
#include <arpa/inet.h>
 
//#define buffsize  150
void main()
{
int b,sockfd,sin_size,con,n,len;
//char buff[256];
char operator,ch;
int op1,op2,result;
FILE *fp;
 
if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");
//printf("%d\n", sockfd);
struct sockaddr_in servaddr;
 
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=6006;
 
sin_size = sizeof(struct sockaddr_in);
if((con=connect(sockfd,(struct sockaddr *) &servaddr, sin_size))==0); 
//initiate a connection on a socket
printf("connect sucessful\n");
 
//1 send hello
write(sockfd,"HELLO FROM CLIENT", sizeof("HELLO FROM CLIENT"));
 
//
//2 To receive file
fp = fopen("b.txt", "w");
read(sockfd,&ch,sizeof(ch));
while(ch!=EOF)
{		
	fputc(ch,fp);
	read(sockfd,&ch,sizeof(ch));
}
printf("FILE RECEIVED\n");
fclose(fp);
 
//3 maths ops
printf("Enter operation:\n +:Addition \n -: Subtraction \n /: Division 
					\n*:Multiplication \n");
scanf("%c",&operator);
printf("Enter operands:\n");
scanf("%d %d", &op1, &op2);
 
write(sockfd,&operator,10);
write(sockfd,&op1,sizeof(op1));
write(sockfd,&op2,sizeof(op2));
read(sockfd,&result,sizeof(result)); 
printf("Operation result from server=%d\n",result);  
close(sockfd);
}
 
/*
OUTPUT OF CLIENT
 
student@student-OptiPlex-3020:~$ gcc -o c.out ccalculator.c 
student@student-OptiPlex-3020:~$ ./c.out
socket created sucessfully
connect sucessful
FILE RECEIVED
Enter operation:
 +:Addition 
 -: Subtraction 
 /: Division 
*:Multiplication 
*
Enter operands:
2
3
Operation result from server=6
student@student-OptiPlex-3020:~$ ./c.out
socket created sucessfully
connect sucessful
FILE RECEIVED
Enter operation:
 +:Addition 
 -: Subtraction 
 /: Division 
*:Multiplication 
/
Enter operands:
4
2
Operation result from server=2
student@student-OptiPlex-3020:~$ ./c.out
socket created sucessfully
connect sucessful
FILE RECEIVED
Enter operation:
 +:Addition 
 -: Subtraction 
 /: Division 
*:Multiplication 
-
Enter operands:
5
7
Operation result from server=-2
student@student-OptiPlex-3020:~$ ./c.out
socket created sucessfully
connect sucessful
FILE RECEIVED
Enter operation:
 +:Addition 
 -: Subtraction 
 /: Division 
*:Multiplication 
+
Enter operands:
7
8
Operation result from server=15
student@student-OptiPlex-3020:~$ 
 
*/
