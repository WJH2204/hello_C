#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#define N 20

int main()
{
	char arr[N][N] = { 0 };
	int i = 0, j = 0, k = 0;
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			arr[i][j] = ' ';
		}

	}
	for (i = 0; i <= (N - 1) / 2; i++)
	{
		for (j = i, k = N / 2 - i; (j <= N / 2 + i) && (k <= N - 1 - i); )
		{
			arr[j][k] = '*';
			if ((j != i) && (i != (N - 1) / 2))
			{
				arr[j][k - 1] = '*';
			}
			k++;
			j++;
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}

}