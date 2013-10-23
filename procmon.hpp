#include<sys/types.h>


#define MAX_BUF 10

enum {
UDP_SERVER,
TCP_SERVER,
UNIX_SERVER
};

enum {
RETURN_OK,
E_SELECT_TIMEOUT,
E_SELECT_ERROR,
};

struct procmsg {
	pid_t p;
	int hash;
};

typedef procmsg PM;

struct proclist {
    int pid[MAX_BUF][4];
    time_t t[MAX_BUF];
};

typedef proclist P


int sock_server(int);
int proc_ack(int);

