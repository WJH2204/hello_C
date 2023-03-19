#include "stack.h"

void test()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 4);
	StackPush(&s, 4);
	StackPush(&s, 4);
	StackPush(&s, 4);

	
	while (!IsEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}

}

int main()
{
	
	test();
	return 0;
}