#include "Heap.h"

void HeapCreate(Heap* ph)
{
	assert(ph);

	ph->a = (HPDatetype*)malloc(sizeof(HPDatetype) * 4);
	if (ph->a == NULL)
	{
		perror("HeapCreate");
		exit(-1);
	}

	ph->capacity = 4;
	ph->size = 0;
}

void HeapDestory(Heap* ph)
{
	assert(ph);

	free(ph->a);
	ph->a = NULL;
}

void Swap(HPDatetype* elem1, HPDatetype* elem2)
{
	assert(elem1 && elem2);

	HPDatetype tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

void Adjustup(Heap* ph, int pos)
{
	assert(ph);

	int child = pos;
	int parent = (child - 1) / 2;

	while (child > 0 && ph->a[child] < ph->a[parent])
	{
		Swap(&ph->a[child], &ph->a[parent]);

		child = parent;
		parent = (child - 1) / 2;
	}
}

void HeapPush(Heap* ph, HPDatetype val)
{
	assert(ph);
	if (ph->size == ph->capacity)
	{
		int newcapacity = ph->capacity * 2;
		HPDatetype* tmp = (HPDatetype*)realloc(ph->a, sizeof(HPDatetype) * newcapacity);
		if (tmp == NULL)
		{
			perror("HeapPush");
			exit(-1);
		}

		ph->a = tmp;
		ph->capacity = newcapacity;
	}

	ph->a[ph->size] = val;
	ph->size++;

	Adjustup(ph, ph->size-1);
}

void AdjustDown(Heap* ph)
{
	assert(ph);

	int parent = 0;
	int minchild = 2 * parent + 1;

	while (minchild < ph->size)
	{
		if (minchild + 1 < ph->size && ph->a[minchild] > ph->a[minchild + 1])
		{
			minchild = minchild + 1;
		}

		if (ph->a[parent] > ph->a[minchild])
		{
			Swap(&ph->a[parent], &ph->a[minchild]);

			parent = minchild;
			minchild = 2 * parent + 1;
		}
		else
		{
			break;
		}
	}


}

void HeapPop(Heap* ph)
{
	assert(ph);
	assert(!HeapEmpty(ph));

	Swap(&ph->a[0], &ph->a[ph->size - 1]);

	ph->size--;

	AdjustDown(ph);
}

HPDatetype HeapTop(Heap* ph)
{
	assert(ph);
	assert(!HeapEmpty(ph));

	return ph->a[0];
}

int HeapSize(Heap* ph)
{
	assert(ph);

	return ph->size;
}

int HeapEmpty(Heap* ph)
{
	assert(ph);

	return ph->size == 0;
}

void PrintTopK(int* a, int n, int k) //xiaodui
{
	Heap h;
	HeapCreate(&h);

	int i = 0;

	for (i = 0; i < n; i++)
	{
		HeapPush(&h, a[i]);
	}

	for (i = 0; i < k; i++)
	{
		printf("%d ", HeapTop(&h));
		HeapPop(&h);
	}

	HeapDestory(&h);
}
