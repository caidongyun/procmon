#include<sys/types.h>


#define MAX_BUF 10

enum server_type {
UDP_SERVER,
TCP_SERVER,
UNIX_SERVER
};

enum return_codes{
RETURN_OK,
E_SELECT_TIMEOUT,
E_SELECT_ERROR,
E_ERROR=-1
};

enum packet_type {
INIT=1,
INIT_ACK,
PING,
DEL,
ACK
};

struct procmsg {
	int packet_type;
	int info;
	pid_t p;
	int hash;
};

typedef struct procmsg PM;

struct proclist {
    int pid[MAX_BUF][4];
    time_t t[MAX_BUF];
};

typedef struct proclist P;

P _plist;


int sock_server(int);
int proc_ack(int);

