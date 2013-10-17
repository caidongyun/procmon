#include<list>
#include<sys/time.h>

class procmon
{
	public:
	void m_kick();
//	static char msg='A';	
//	private:
	std::list<int> m_timer_list;
	std::list<int>::iterator i;
};
