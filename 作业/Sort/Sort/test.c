#include "Sort.h"

int main()
{
	int a[] = { 103,104,105,101,102 };
	//InsertSort(a, sizeof(a) / sizeof(a[0]));

	//ShellSort(a, sizeof(a) / sizeof(a[0]));

	//SelectSort(a, sizeof(a) / sizeof(a[0]));

	//HeapSort(a, sizeof(a) / sizeof(a[0]));

	//BubbleSort(a, sizeof(a) / sizeof(a[0]));

	//QuickSort(a, 0, sizeof(a) / sizeof(a[0]) - 1);

	//QuickSortNonRecursive(a, 0, sizeof(a) / sizeof(a[0]) - 1);

	//MergeSortNonRecursive(a, sizeof(a) / sizeof(a[0]));

	CountSort(a, sizeof(a) / sizeof(a[0]));

	PrintArr(a, sizeof(a) / sizeof(a[0]));

	return 0;
}

