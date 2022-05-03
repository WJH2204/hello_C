#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

void printfmultab(n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			printf("%d*%d=%d\t", j, i, i*j);
		}
		printf("\n");
	}
}

int main()
{
	int n = 0;
	scanf("%d", &n);
	printfmultab(n);
	return 0;
}