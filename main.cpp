#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/select.h>
#include <unistd.h>
#include <signal.h>

#include "procmon.hpp"


static P plist;
static int _got_alarm;

int main()
{
	int val=10, sockfd;
	sockfd= sock_server(UDP_SERVER);

	for(;;)
		wait_on_socket(sockfd);
		proc_ack(sockfd);

	return 0;
}
