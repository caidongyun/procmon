#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "unix-sr.c"

#define MAX_BUF 2048


struct proclist {
	int pid[MAX_BUF];
	struct itimerval itv[MAX_BUF];
	int sockfd[MAX_BUF];
	int (*kick)(int pid, struct itimerval*);
};

typedef proclist P;

int populate_list(P *plist)
{
	int i=0;
	for(;i<10;i++){
		plist->pid[i]=i;
		plist->itv[i]=i;
	}

	return 0;
}

int
main()
{
	int val=10, sockfd;
	P plist;
	populate_list(&plist);

	sockfd=unix_server();
	return 0;
}
