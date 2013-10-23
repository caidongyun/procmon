
/* Sample UDP client */

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "procmon.hpp"


int register_client(int sockfd,struct sockaddr_in* servaddr)
{
	
	int n;
	PM init_packet,recv_packet;
	init_packet.packet_type=INIT;
	init_packet.pid=getpid();
	
	if (sendto(sockfd,&init_packet,sizeof(PM),0
					(struct sockaddr *)servaddr,sizeof(servaddr)) < 0)
		perror("sendto in register client");
		
	n=recvfrom(sockfd,&recv_packet,sizeof(PM),0,NULL,NULL);
	if(n < sizeof(PM))
		printf("Did not get complete packet from Server\n");
	recv_packet.info++;
	
	if (sendto(sockfd,&recv_packet,sizeof(PM),0
					(struct sockaddr *)servaddr,sizeof(servaddr)) < 0)
		perror("sendto in register client");
	memset(recv_packet,0,sizeof(PM));
	n=recvfrom(sockfd,&recv_packet,sizeof(PM),0,NULL,NULL);
	if(n < sizeof(PM))
		printf("Did not get complete packet from Server\n");
	if (recv_packet.packet_type == ACK)
		printf("Client registration with Procmon Complete\n");
	return 0;
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

   register_client(sockfd,&servaddr);
   return 0;
}
