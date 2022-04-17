#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int i = 0;
	int j = 0;
	for (i = 100; i < 201; i++)
	{
		for (j = i - 1; j > 1; j--)
		{
			if (i % j == 0)
				break;
			else if (j == 2)
			{
				printf("%d ", i);
			}
		}

	}
	return 0;
}