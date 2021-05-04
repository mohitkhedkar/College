//---SERVER SIDE----
#include<sys/types.h>
#include<sys/socket.h> 
#include<stdio.h>
#include<netinet/in.h> 
#include <unistd.h>
#include<string.h> 
#include <arpa/inet.h> 
 
void main()
{
int b,sockfd,connfd,sin_size,l,n,len;
char operator, msg[25], ch;
int op1,op2,result;
FILE * fp;
 
if((sockfd=socket(AF_INET,SOCK_STREAM,0))>0)
printf("socket created sucessfully\n");  //socket creation
//printf("%d\n", sockfd);                 //on success 0 otherwise -1
 
struct sockaddr_in servaddr;              
struct sockaddr_in clientaddr;
 
servaddr.sin_family=AF_INET;
servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
servaddr.sin_port=6006;
 
if((bind(sockfd, (struct sockaddr *)&servaddr,sizeof(servaddr)))==0)
printf("bind sucessful\n");   //bind() assigns the
     //  address  specified  by  addr  to  the  socket  referred  to by the file
      // descriptor sockfd.  addrlen  specifies  the  size,  in  bytes,  of  the
     //  address structure pointed to by addr.  Traditionally, this operation is
      // called “assigning a name to a socket”.
 
//printf("%d\n",b);
 
if((listen(sockfd,5))==0) //listen for connections on a socket
printf("listen sucessful\n");
//printf("%d\n",l);
 
sin_size = sizeof(struct sockaddr_in);
if((connfd=accept(sockfd,(struct sockaddr *)&clientaddr,&sin_size))>0);
printf("accept sucessful\n");
	
//To receive hello msg from client
read(connfd, &msg,sizeof(msg));
printf("%s\n",msg);
 
//To send file
fp = fopen("a.txt", "r");
ch=fgetc(fp);
while(ch!=EOF)
{
	write(connfd,&ch,sizeof(ch));
	ch=fgetc(fp);
}
write(connfd,&ch,sizeof(ch));
printf("FILE SENT\n");
fclose(fp);
 
 
//Maths operations
read(connfd, &operator,10);
read(connfd,&op1,sizeof(op1));
read(connfd,&op2,sizeof(op2));
switch(operator) {
        case '+': result=op1 + op2;
         printf("Result is: %d + %d = %d\n",op1, op2, result);
         break;
        case '-':result=op1 - op2;
                printf("Result is: %d - %d = %d\n",op1, op2, result);
                break;
        case '*':result=op1 * op2;
                printf("Result is: %d * %d = %d\n",op1, op2, result);
                break;
        case '/':result=op1 / op2;
                printf("Result is: %d / %d = %d\n",op1, op2, result);
                break;
        default: 
                printf("ERROR: Unsupported Operation");
    }
  
write(connfd,&result,sizeof(result));   
close(sockfd);
}
 
 
/*
OUTPUT OF SERVER
 
student@student-OptiPlex-3020:~$ gcc scalculator.c 
student@student-OptiPlex-3020:~$ gcc -o s.out scalculator.c 
student@student-OptiPlex-3020:~$ ./s.out
socket created sucessfully
bind sucessful
listen sucessful
accept sucessful
HELLO FROM CLIENT
FILE SENT
Result is: 2 * 3 = 6
 
student@student-OptiPlex-3020:~$ ./s.out
socket created sucessfully
bind sucessful
listen sucessful
accept sucessful
HELLO FROM CLIENT
FILE SENT
Result is: 4 / 2 = 2
 
student@student-OptiPlex-3020:~$ ./s.out
socket created sucessfully
bind sucessful
listen sucessful
accept sucessful
HELLO FROM CLIENT
FILE SENT
Result is: 5 - 7 = -2
 
student@student-OptiPlex-3020:~$ 
student@student-OptiPlex-3020:~$ ./s.out
socket created sucessfully
bind sucessful
listen sucessful
accept sucessful
HELLO FROM CLIENT
FILE SENT
Result is: 7 + 8 = 15
student@student-OptiPlex-3020:~$ 
 
*/ 

