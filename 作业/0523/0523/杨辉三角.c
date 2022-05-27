#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int arr[100][100] = { 0 };

	int n = 0;
	scanf("%d", &n);

	int i = 0, j = 0;

	for (i = 0; i < n; i++)
	{
		arr[i][0] = 1;
		arr[i][i] = 1;
		for (j = 1; j < i; j++)
		{
			arr[i][j] = arr[i - 1][j - 1] + arr[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
		{
			printf("%d\t", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}