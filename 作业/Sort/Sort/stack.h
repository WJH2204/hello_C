#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDateType;

typedef struct Stack
{
	STDateType* stack;
	int top;
	int capacity;

} Stack;

void StackInit(Stack* ps);

void StackPush(Stack* ps, STDateType val);

STDateType StackTop(Stack* ps);

int StackSize(Stack* ps);

void StackDestroy(Stack* ps);

bool IsEmpty(Stack* ps);

void StackPop(Stack* ps);