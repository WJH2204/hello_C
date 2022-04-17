#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int result = 0;
	scanf("%d %d", &a, &b);

	if (a >= b)
	{
		for (result = b; a % result != 0 || b % result != 0; result--)
		{
			;
		}
		printf("%d", result);
	}
	else
	{
		for (result = a; a % result != 0 || b % result != 0; result--)
		{
			;
		}
		printf("%d", result);
	}
	return 0;
}