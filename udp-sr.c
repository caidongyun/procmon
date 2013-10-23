/* Sample UDP server */

#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/select.h>
#include <stdio.h>
#include <string.h>
#include "promon.hpp"

int udp_server()
{
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   socklen_t len;
   char mesg[1000];
   fd_set rfds;
   struct timeval tv;
   int retval;

   sockfd=socket(AF_INET,SOCK_DGRAM,0);

//   bzero(&servaddr,sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr=htonl(INADDR_ANY);
   servaddr.sin_port=htons(32000);
   bind(sockfd,(struct sockaddr *)&servaddr,sizeof(servaddr));
   return sockfd;
}

int proc_ack(int sockfd)
   
   int sockfd,n;
   struct sockaddr_in servaddr,cliaddr;
   socklen_t len;
   char mesg[1000];
   fd_set rfds;
   struct timeval tv;
   int retval;

   for (;;)
   {
		   FD_ZERO(&rfds);
		   FD_SET(sockfd,&rfds);

		   tv.tv_sec =10;
		   tv.tv_usec = 0;

		   retval = select(sockfd+1,&rfds,NULL,NULL,&tv);
		   if(retval)
		   {
			  len = sizeof(cliaddr);
			  n = recvfrom(sockfd,&m,sizeof(m),0,(struct sockaddr *)&cliaddr,&len);
			  printf("Client PID=%d,Client Hash=%d\n",m.p,m.hash);
		   }
		   if(!retval)
		   {
				/* Timeout should check the time value and kill the process */
				printf("Killed the Non responding Process =%d\n",m.pid);
				kill(SIGKILL,m.pid);
		   }
   }
}

int tcp_server()
{
	return 0;
}

int unix_server()
{
	return 0;
}

int sock_server(int server_type)
{
	switch(server_type):
		{
		case 0:
			return udp_server();
		case 1:
			return tcp_server();
		case 2:
			return unix_server();
		}
	return 0;

}


