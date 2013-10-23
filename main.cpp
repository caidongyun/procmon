#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/select.h>
#include <unistd.h>
#include <signal.h>

#include "unix-sr.c"

#define MAX_BUF 10


struct proclist {
	int pid[MAX_BUF][4];
	time_t t[MAX_BUF];
	int (*kick)(pid_t pid,time_t *t);
};

typedef proclist P;

static P plist;
static int _got_alarm;

int handle_signal()
{
	return 0;
}


int kick (int hash,P * plist)
{
	return plist->t[hash]=0;
	
}

int populate_list(P *plist)
{
	int i=0;
	for(;i<10;i++){

	}
	return 0;
}

int proc_restart()
{
	printf("In proc restart\n");
	return 0;
}

int proc_ping(int sockfd, P *plist)
{
	fd_set rfds;
	struct timeval tv;
	int retval;
	
	FD_ZERO(&rfds);
	FD_SET(sockfd, &rfds);

	/* Wait up to five seconds. */
	tv.tv_sec = 5;
	tv.tv_usec = 0;

	retval = select(1, &rfds, NULL, NULL, &tv);
	/* Don't rely on the value of tv now! */

	if (retval){
	   printf("Data is available now.\n");
	   /* FD_ISSET(0, &rfds) will be true. */
	   //hash=process_packet(sockfd);
   }else if(!retval) {
	   proc_restart();
   }	
}

int
main()
{
	int val=10, sockfd;
	populate_list(&plist);
	sockfd= unix_server();
	proc_ping(&plist);
//	signal(SIGALRM,handle_signal);
	return 0;
}
