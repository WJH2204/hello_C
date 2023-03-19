#include <iostream>
#include "stack.h"
#include "queue.h"
#include "priority_queue.h"

int main()
{
	my::priority_queue<int> pq;
	pq.push(0);
	pq.push(1);
	pq.push(2);
	pq.push(3);
	pq.push(4);
	pq.push(5);
	pq.push(6);

	pq.pop();

	while ( !pq.empty() )
	{
		std::cout << pq.top();
		pq.pop();
	}

	std::cout << std::endl;

	//my::queue<int> q;
	//q.push(0);
	//q.push(1);
	//q.push(2);
	//q.push(3);

	//q.pop();

	//while (!q.empty())
	//{
	//	std::cout << q.front();
	//	q.pop();
	//}

	//std::cout << std::endl;

	return 0;
}