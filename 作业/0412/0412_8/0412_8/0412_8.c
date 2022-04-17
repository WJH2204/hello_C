#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	for (i = 3; i < 101; i += 3)
	{
		printf("%d ", i);
	}
	return 0;
}