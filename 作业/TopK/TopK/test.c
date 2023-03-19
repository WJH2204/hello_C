#include "TopK.h"

int main()
{
	const char* filename = "Date.txt";

	srand((unsigned int)time(NULL));

	int N = 1000;
	int k = 5;

	//CreateDate(filename, N);

	int* a = (int*)malloc(sizeof(int) * N);
	if (a == NULL)
	{
		perror("malloc");
		exit(-1);
	}

	ReadDate(filename, a);


	HeapTopK(a, k);

	CompareRootWithOther(a, N, k);

	HeapSort(a, k);

	int i = 0;
	for (i = 0; i < k; i++)
	{
		printf("%d ", a[i]);
	}

	free(a);
	a = NULL;

	return 0;
}