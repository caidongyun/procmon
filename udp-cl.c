
/* Sample UDP client */

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct mymsg {
	pid_t p;
	int hash;
}m;

int register_client(int sockfd,struct mymsg *m)
{
	sendto(sockfd,sendline,strlen(sendline),0
					(struct sockaddr *)&servaddr,sizeof(servaddr));
	n=recvfrom(sockfd,recvline,10000,0,NULL,NULL);
}

int main(int argc, char**argv)
{
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   char sendline[1000];
   char recvline[1000];
   
   sockfd=socket(AF_INET,SOCK_DGRAM,0);

   bzero(&servaddr,(socklen_t)sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=inet_addr("127.0.0.1");
   servaddr.sin_port=htons(32000);

   m.p=getpid();
   m.hash=1;
   register_client(sockfd,&m);
   return 0;
}
