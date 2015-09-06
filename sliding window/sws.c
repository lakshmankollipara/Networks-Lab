#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>
void error(char *msg){    perror(msg);    exit(0);}
int main(int argc, char *argv[]){
	int sockfd, newsockfd, portno, clilen;
	char buffer[256],a[10],c[5];
	struct sockaddr_in serv_addr, cli_addr;
	int n,t;
	if (argc < 2) { fprintf(stderr,"ERROR, no port provided\n"); exit(1); }
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if (sockfd < 0) error("ERROR opening socket");
	bzero((char *) &serv_addr, sizeof(serv_addr));
	portno = atoi(argv[1]);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv_addr.sin_port = htons(portno);
if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) 		
error("ERROR on binding");
	listen(sockfd,5);
	clilen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, &clilen);
	if (newsockfd < 0) error("ERROR on accept");
	bzero(buffer,256);
	if (n < 0) error("ERROR reading from socket");
        bzero(buffer,256);
        n = recv(newsockfd,buffer,255,0);
you:
        printf("here is the content : %s\n",buffer);
        printf("enter ack or nack\n");
        scanf("%s",a);
        n = send(newsockfd,a,strlen(a),0);
  if(strcmp(a,"ack")==0)
{
        bzero(buffer,256);
        n = recv(newsockfd,buffer,255,0);
        if(strlen(buffer)!=0)
        goto you;
        else
        {close(sockfd);
close(newsockfd);
}
}
else
{
bzero(buffer,256);
n = recv(newsockfd,buffer,255,0);
goto you;
}
}
