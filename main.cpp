#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define MAX_BUF 2048


struct proclist {
	int pid[MAX_BUF];
	struct itimerval itv[MAX_BUF];
	int sockfd[MAX_BUF];
};

typedef proclist P;

int populate_list(P *plist)
{
	int i=0;
	for(;i<10;i++)
		plist->pid[i]=i;

	return 0;
}

int
main()
{
	int val=10;
	P plist;
	populate_list(&plist);
	for(val=0;val < 10; val++)
		printf("\n==%d\n",plist.pid[val]);

	return 0;
}
