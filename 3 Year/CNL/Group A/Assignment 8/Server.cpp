// Write a program using UDP Sockets to enable file transfer (Script, Text, Audio and Video one file each) between two machines. Demonstrate the packets captured traces using Wireshark Packet Analyzer Tool for peer to peer mode.  (Use C/C++)

// Author: Mohit Khedkar


//----SERVER SIDE----
 
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<sys/socket.h>
 
#define BUFLEN 503
#define PORT 8885
 
void die(char *s)
{
	perror(s);
	exit(1);
}
 
int main(void)
{
	struct sockaddr_in si_me, si_other;
	
	int s, i,j, slen = sizeof(si_other) , recv_len;
	char buf[BUFLEN];
	
	if ((s=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == -1)
	{
		die("socket");
	}
	
	memset((char *) &si_me, 0, sizeof(si_me));
	
	si_me.sin_family = AF_INET;
	si_me.sin_port = htons(PORT);
	si_me.sin_addr.s_addr = htonl(INADDR_ANY);
	
	if( bind(s , (struct sockaddr*)&si_me, sizeof(si_me) ) == -1)
	{
		die("bind");
	}
	//memset(buf,0,503);
	char fname[20];
	FILE *fp;
	recv_len = recvfrom(s, buf, 20, 0, (struct sockaddr *) &si_other, &slen);
	/*if ((recv_len = recvfrom(s, fname, 20, 0, 
	(struct sockaddr *) &si_other, &slen)) == -1)
	{
		die("recvfrom()");
	}*/
	char fna[100];
	//strcpy(fna,"/home/krishna/ftp new/");	
//replace krishna by current username
	//strcat(buf,"_new");
	strcpy(fna,buf);
	//printf("------%s",buf);
	memset(buf,0,503);
	recv_len = recvfrom(s, buf, 20, 0, (struct sockaddr *) &si_other, &slen);
	
	/*if ((recv_len = recvfrom(s, buf, 20, 0,
	 (struct sockaddr *) &si_other, &slen)) == -1)
	{
		die("recvfrom()");
	}*/
	//printf("%s",buf);
	
	int len= strlen(fna);
	//printf("%d",len);
	for(j=len-1;j>=0;j--)
	{
		if(fna[j]=='.')
		{
			fna[j-1]='1';
		}
	}
	unsigned long mm = atoi(buf);
	//fp=fopen("ve1.mp4","wb");
	//fp=fopen("mysiren1.mp3","wb");
	
	fp=fopen(fna,"wb");
	int itr=1;
	memset(buf,0,503);
	while(itr*503<mm)
	{
	if ((recv_len = recvfrom(s, buf, 503, 0, 
		(struct sockaddr *) &si_other, &slen)) == -1)
	
			die("recvfrom()");
		}
		fwrite(buf,503, 1, fp);
		memset(buf,0,503);
		itr++;
	}
	printf("%d",(mm%503));
	recv_len = recvfrom(s, buf, (mm%503), 0, 
			(struct sockaddr *) &si_other, &slen);
/*if ((recv_len = recvfrom(s, buf, (mm%503), 0, 
		(struct sockaddr *) &si_other, &slen)) == -1)
	{
		die("recvfrom()");
	}*/
	fwrite(buf,(mm%503), 1, fp);
	memset(buf,0,503);
	fclose(fp);
	close(s);
	//shutdown(s, SHUT_WR);
	return 0;
}
 
	

