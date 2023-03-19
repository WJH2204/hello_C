#include "Sort.h"

//ÉýÐò

void Swap(SortDateType* elem1, SortDateType* elem2)
{
	assert(elem1 && elem2);

	int tmp = *elem1;
	*elem1 = *elem2;
	*elem2 = tmp;
}

void InsertSort(int* a, int n)
{
	int i = 0;
	int end = 0;
	int inserted_val = 0;
	for (i = 0; i < n - 1; i++)
	{
		end = i;
		inserted_val = a[end + 1];
		while (end >= 0)
		{
			if (a[end] > inserted_val)
			{
				a[end + 1] = a[end];
				end--;
			}
			else
				break;
		}
		a[end + 1] = inserted_val;
	}

}

void ShellSort(SortDateType* a, int n)
{
	assert(a);

	int i = 0;
	int end = 0;
	int inserted_val = 0;
	int gap = n;

	while (gap > 1)
	{
		gap = gap / 3 + 1;
		
		for (i = 0; i < n - gap; i++)
		{
			end = i;
			inserted_val = a[end + gap];
			while (end >= 0)
			{
				if (a[end] > inserted_val)
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = inserted_val;
		}

	}
}

void SelectSort(SortDateType* a, int n)
{
	assert(a);

	int i = 0;
	int min_i = 0;
	int max_i = 0;
	int begin = 0;
	int end = n - 1;
	while (begin < end)
	{
		min_i = begin;
		max_i = end;
		for (i = begin; i <= end; i++)
		{
			if (a[i] < a[min_i])
				min_i = i;
			if (a[i] > a[max_i])
				max_i = i;
		}
		Swap(&a[begin], &a[min_i]);

		if (max_i == begin)
			Swap(&a[min_i], &a[end]);
		else
			Swap(&a[max_i], &a[end]);

		begin++;
		end--;
	}
}

void AdjustDown(int* a, int n, int root)
{
	while (root < n)
	{
		int maxchild = root * 2 + 1;
		if (maxchild + 1 < n && a[maxchild + 1] > a[maxchild])
			maxchild++;
		if (maxchild < n && a[maxchild] > a[root])
			Swap(&a[maxchild], &a[root]);
		root = maxchild;
	}
}

void HeapSort(int* a, int n)
{
	assert(a);

	int i = 0;
	for (i = (n - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(a, n, i);
	}

	int end = n - 1;

	for (end = n - 1; end > 0; --end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end - 1, 0);
	}
}

void BubbleSort(int* a, int n)
{
	assert(a);

	int i = 0;
	int j = 0;
	for (j = 0; j < n; j++)
	{
		for (i = 0; i < n - 1 - j; i++)
		{
			if (a[i] > a[i + 1])
				Swap(&a[i], &a[i + 1]);
		}
	}
}

int GetMiddleVal(int* a, int left, int right)
{
	int mid = left + (right - left) / 2;

	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else //a[left] > a[mid]
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] > a[right])
			return right;
		else
			return left;
	}

}

int PartSort1(int* a, int left, int right)
{
	assert(a);

	int mid = GetMiddleVal(a, left, right);
	Swap(&a[left], &a[mid]);

	int key_i = left;

	while (left < right)
	{
		while (left < right && a[right] >= a[key_i])
		{
			right--;
		}
		while (left < right && a[left] <= a[key_i])
		{
			left++;
		}

		Swap(&a[left], &a[right]);
	}
	Swap(&a[left], &a[key_i]);

	return left;
}

int PartSort2(int* a, int left, int right)
{
	assert(a);

	int mid = GetMiddleVal(a, left, right);
	Swap(&a[left], &a[mid]);

	int pit = left;

	int key = a[pit];


	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[pit] = a[right];
		pit = right;

		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[pit] = a[left];
		pit = left;
	}
	a[pit] = key;

	return pit;
}

int PartSort3(int* a, int left, int right)
{
	assert(a);

	int mid = GetMiddleVal(a, left, right);
	Swap(&a[left], &a[mid]);

	int key_i = left;
	int prev = left;
	int cur = prev + 1;

	while (cur <= right)
	{
		if (a[cur] <= a[key_i])
		{
			prev++;
			if (prev != cur)
				Swap(&a[prev], &a[cur]);
		}

		cur++;
	}
	Swap(&a[prev], &a[key_i]);

	return prev;
}

void QuickSort(int* a, int left, int right)
{
	assert(a);

	if (right - left < 8)
	{
		InsertSort(a + left, right - left + 1);
		return;
	}

	int key_i = PartSort3(a, left, right);
	QuickSort(a, left, key_i - 1);
	QuickSort(a, key_i + 1, right);
}

void QuickSortNonRecursive(int* a, int left, int right)
{
	Stack st;
	StackInit(&st);

	StackPush(&st, left);
	StackPush(&st, right);

	int key_i = 0;

	while (!IsEmpty(&st))
	{
		right = StackTop(&st);
		StackPop(&st);

		left = StackTop(&st);
		StackPop(&st);

		key_i = PartSort2(a, left, right);

		if (key_i + 1 < right)
		{
			StackPush(&st, key_i + 1);
			StackPush(&st, right);
		}
		
		if (left < key_i - 1)
		{
			StackPush(&st, left);
			StackPush(&st, key_i - 1);
		}
	}


	StackDestroy(&st);

}

void PrintArr(SortDateType* a, int n)
{
	assert(a);

	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
}

void _MergeSort(int* a, int* tmp, int left, int right)
{
	if (left >= right)
		return;

	int mid = (right - left) / 2 + left;
	_MergeSort(a, tmp, left, mid);
	_MergeSort(a, tmp, mid + 1, right);

	int left1 = left;
	int right1 = mid;
	int left2 = mid + 1;
	int right2 = right;
	int j = left;

	while (left1 <= right1 && left2 <= right2)
	{
		if (a[left1] <= a[left2])
			tmp[j++] = a[left1++];

		else
			tmp[j++] = a[left2++];
	}

	while (left1 <= right1)
	{
		tmp[j++] = a[left1++];
	}

	while (left2 <= right2)
	{
		tmp[j++] = a[left2++];
	}

	while (left <= right)
	{
		a[left] = tmp[left++];
	}

}

void MergeSort(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	_MergeSort(a, tmp, 0, n - 1);
}

void MergeSortNonRecursive(int* a, int n)
{
	assert(a);
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}

	int gap = 1;
	while (gap < n)
	{
		for (int i = 0; i < n; i += 2 * gap)
		{
			int left1 = i;
			int right1 = left1 + gap - 1;
			int left2 = right1 + 1;
			int right2 = left2 + gap - 1;
			int j = left1;

			while (left1 <= right1 && left1 < n && left2 <= right2 && left2 < n)
			{
				if (a[left1] <= a[left2])
					tmp[j++] = a[left1++];

				else
					tmp[j++] = a[left2++];
			}

			while (left1 <= right1 && left1 < n)
			{
				tmp[j++] = a[left1++];
			}

			while (left2 <= right2 && left2 < n)
			{
				tmp[j++] = a[left2++];
			}
		}
		memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
}

void CountSort(int* a, int n)
{
	assert(a);
	int max = a[0];
	int min = a[0];
	int i = 0;
	for (i = 1; i < n; i++)
	{
		if (a[i] > max)
			max = a[i];
		if (a[i] < min)
			min = a[i];
	}

	int size_alloc = max - min + 1;
	int* count = (int*)calloc(n, sizeof(int));

	if (count == NULL)
	{
		perror("malloc fail");
		exit(-1);
	}
	for (i = 0; i < n; i++)
	{
		count[a[i] - min]++;
	}
	int j = 0;
	for (i = 0; i < n;)
	{
		while (count[j]--)
		{
			a[i++] = j + min;
		}
		j++;
	}
}

