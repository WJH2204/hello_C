#include "queue.h"

void test()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueHead(&q));

		QueuePop(&q);

	}



	QueueDestroy(&q);


}

int main()
{
	test();
	return 0;
}