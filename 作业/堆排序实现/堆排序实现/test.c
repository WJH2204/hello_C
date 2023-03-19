#include "HeapSort.h"

int main()
{
	srand((unsigned int)time(NULL));

	int N = 10;

	CreateDate("Data.txt", N);

	int* a = (int*)malloc(sizeof(int) * N);
	if (a == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	ReadDate("Data.txt", a);
	
	HeapSort(a, N);

	int i = 0;
	for (i = 0; i < N; i++)
	{
		printf("%d ", a[i]);
	}

	free(a);
	a = NULL;

	return 0;
}
