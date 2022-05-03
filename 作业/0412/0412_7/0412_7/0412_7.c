#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void swap(int* px, int* py);

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d %d", &a, &b, &c);
	if (a < b)
	{
		swap(&a, &b);
	}
	if (a < c)
	{
		swap(&a, &c);
	}
	if ( b < c)
	{
		swap(&b, &c);
	}
	printf("%d %d %d", a, b, c);
	return 0;
}

void swap(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
