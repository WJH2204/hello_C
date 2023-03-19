#include "stack.h"

void StackInit(Stack* ps)
{
	assert(ps);

	ps->stack = (STDateType*)malloc(sizeof(STDateType) * 4);
	if (ps->stack == NULL)
	{
		perror("StackInit");
		exit(-1);
	}

	ps->top = 0;
	ps->capacity = 4;
}

void StackPush(Stack* ps, STDateType val)
{
	assert(ps);

	if (ps->top == ps->capacity)
	{
		int newcapacity = 2 * ps->capacity;

		STDateType* tmp = (STDateType*)realloc(ps->stack, sizeof(STDateType) * newcapacity);
		if (tmp == NULL)
		{
			perror("StackPush");
			exit(-1);
		}

		ps->stack = tmp;
		ps->capacity = newcapacity;
	}

	ps->stack[ps->top] = val;
	ps->top++;
}

bool IsEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}


void StackPop(Stack* ps)
{
	assert(ps);
	assert(!IsEmpty(ps));

	ps->top--;
}

STDateType StackTop(Stack* ps)
{
	assert(ps);
	assert(!IsEmpty(ps));

	return ps->stack[ps->top - 1];
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}

void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->stack);

	ps->stack = NULL;
	ps->capacity = 0;
	ps->top = 0;

}