#include<iostream>
#include<new>
#include"procmon.hpp"

int main()
{
	procmon mymon;
	mymon.m_timer_list.push_back(10);
	mymon.m_timer_list.push_back(11);
	mymon.m_timer_list.push_back(12);

	for(mymon.i; mymon.i != mymon.m_timer_list.end();mymon.i++)
		std::cout << mymon.m_timer_list(*(mymon.i)) ;
	return 0;
}
