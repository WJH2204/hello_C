#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int fib(int n)
{
	if (n > 2)
		return fib(n - 1) + fib(n - 2);
	return 1;
}

int main()
{
	int a = 0;
	scanf("%d", &a);
	int ret = fib(a);
	printf("%d", ret);
	return 0;
}