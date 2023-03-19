#include "list.h"

struct pos
{
	int _a;
	int _b;

	pos(int a = 0, int b = 0)
		:_a(a)
		,_b(b)
	{
		;
	}
};

int main()
{
	

	my::list<int> ls;
	ls.push_back(0);
	ls.push_back(1);
	ls.push_back(2);
	ls.push_back(3);
	my::list<int>::const_reverse_iterator it = ls.crbegin();
	
	while (it != ls.crend())
	{
		std::cout << *it << std::endl;
		++it;
	}

	std::cout << std::endl;

	return 0;
}