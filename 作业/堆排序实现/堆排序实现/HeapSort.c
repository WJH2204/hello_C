#include "HeapSort.h"

void Swap(int* elem1, int* elem2)
{
	assert(elem1 && elem2);

	int tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

void AdjustDown(int* a, int n, int i)
{
	assert(a);

	int parent = i;
	while (parent < n)
	{
		int minchild = 2 * parent + 1;

		if (minchild + 1 < n  && a[minchild] > a[minchild + 1])
		{
			minchild++;
		}

		if (minchild < n && a[minchild] < a[parent])
		{
			Swap(&a[minchild], &a[parent]);
			parent = minchild;
		}
		else
		{
			break;
		}
	}

}


void HeapSort(int* a, int n)
{
	assert(a);

	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(a, n, i);
	}

	for (i = 1; i < n; i++)
	{
		Swap(&a[0], &a[n - i]);
		AdjustDown(a, n - i, 0);
	}
}

void CreateDate(const char* filename, int n)
{
	assert(filename);

	int i = 0;

	FILE* pFile = fopen(filename, "w");
	if (pFile == NULL)
	{
		perror("fout");
		exit(-1);
	}

	for (i = 0; i < n; i++)
	{
		fprintf(pFile, "%d ", rand());
	}

	fclose(pFile);
}

void ReadDate(const char* filename, int* a)
{
	assert(filename && a);

	FILE* pFile = fopen(filename, "r");
	if (pFile == NULL)
	{
		perror("fout");
		exit(-1);
	}

	int i = 0;

	while ((fscanf(pFile, "%d", &a[i])) != EOF)
	{
		i++;
	}

	fclose(pFile);
}
