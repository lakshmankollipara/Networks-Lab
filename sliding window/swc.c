#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include<string.h>
void error(char *msg){    perror(msg);    exit(0);}
int main(int argc, char *argv[]){
	int sockfd, portno, n,w[5],i,k;
	struct sockaddr_in serv_addr;
	struct hostent *server;
	char buffer[256],buffer1[256],buffer2[256],buffer3[256],buffer4[256],b,c,q;
        int r,t,m;
        char *str1,*str2,*str3;
if (argc < 3) {
	  	fprintf(stderr,"usage %s hostname port\n", argv[0]);
		exit(0);
	}
	portno = atoi(argv[2]);
	sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (sockfd < 0)         error("ERROR opening socket");
server = gethostbyname(argv[1]);
	if (server == NULL) {  fprintf(stderr,"ERROR, no such host\n"); exit(0);    }    
	bzero((char *) &serv_addr, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	bcopy((char *)server->h_addr, (char *)&serv_addr.sin_addr.s_addr
		, server->h_length);
	serv_addr.sin_port = htons(portno);
	if (connect(sockfd,&serv_addr,sizeof(serv_addr)) < 0)
		error("ERROR connecting");

	printf("Please enter the message: ");
	bzero(buffer,256);
i=0;
while(b!='.')
{
b=getchar();
buffer[i]=b;
i++;
}
t=i;
r=0;i=0;
str1=buffer;
str2=buffer1;

n=(t/4);
m=(t%4);
while(n!=0)
{
sprintf(str2,"%d",r);
r++;
str2++;
strncpy(str2,str1,4);
str1=str1+4;
str2=str2+4;
n--;
}
if(m>0)
{
str2++;
sprintf(str2,"%d",r);
strncpy(str2,str1,m);
str2=str2+m+1;
*str2='\0';
}
printf("how many packets to be sent?\n");
scanf("%d",&n);
k=0;
i=0;
str2=buffer1;
str3=buffer2;
i=0;
you2:
while(1)
{
if(*str2=='.')
goto you1;
if(!isalpha(*str2))
{
if((*str2==' ')||(*str2=='\n'))
{
*str3=*str2;
str3++;
str2++;
}
else{
if(i==n)
{
goto you1;
}
i++;
str2++;}
}
else
{
*str3=*str2;
str3++;
str2++;
}
}
you1:
 n = send(sockfd,buffer2,strlen(buffer2),0);
strcpy(buffer3,buffer2);
bzero(buffer2,256);
str3=buffer2;
you:
bzero(buffer4,256);
 n = recv(sockfd,buffer4,255,0);
if(strcmp(buffer4,"ack")==0)
{
if(*str2!='.')
{
printf("enter the no. of packets\n");
scanf("%d",&i);
n=n+i;
goto you2;
}
else
{
        close(sockfd);
        return 0;
}
}
else
{
n = send(sockfd,buffer3,strlen(buffer3),0);
goto you;
}
	close(sockfd);
	return 0;
}



