#include<iostream>
#include<new>
#include"procmon.hpp"

#define RESET_TIMER 0
#define SHOOT_PID 1


int proc_check(PM * m)
{
	int what=0;

	if(what == RESET_TIMER)
		goto __reset_time;
	if(what == SHOOT_PID)
		goto __shoot_pid;
	else
		return E_ERROR;
		
__reset_time:
	_plist.t[hash]=0;
	return 0;
	
__shoot_pid:
	_plist.t[hash]=1;
	return 0;
}

int process_msg(PM *m)
{
	switch (m->packet_type) 
	{
	case INIT:
	case ACK_INIT:
		proc_register(m);
		break;
	case PING:
		proc_check(m);
		break;
	default:
		break;
	}
	return 0;
		
}

