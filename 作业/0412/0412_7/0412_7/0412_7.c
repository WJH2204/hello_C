#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int min = 0;
	int mid = 0;
	int max = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b && a < c)
	{
		min = a;
		if (b < c)
		{
			mid = b;
			max = c;
		}
		else
		{
			mid = c;
			max = b;
		}
	}
	else if (a < b && a > c)
	{
		mid = a;
		min = c;
		max = b;
	}
	else if (a > b && a < c)
	{
		mid = a;
		min = b;
		max = c;
	}
	else if (a > b && a > c)
	{
		max = a;
		if (b < c)
		{
			min = b;
			mid = c;
		}
		else
		{
			min = c;
			mid = b;
		}
	}
	printf("%d %d %d", max, mid, min);
	return 0;
}