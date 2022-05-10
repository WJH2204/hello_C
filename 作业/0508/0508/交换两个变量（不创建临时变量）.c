#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int a = 3;
	int b = 5;
	printf("before exchange: %d %d\n", a, b);
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("after exchange: %d %d\n", a, b);
	return 0;
}