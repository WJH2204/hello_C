#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

void print_array(int* a, int size, char* str)
{
	int i = 0;
	printf("%s\n", str);

	for (i = 0; i < size; i++)
	{
		printf("%d ", a[i]);
	}
}

void sort(int* px, int* py, int* pw, int k)
{
	int i = 0, j = 0, w = 0;
	while (i < k && j < k)
	{
		if (px[i] <= py[j])
		{
			pw[w++] = px[i++];
		}
		else
		{
			pw[w++] = py[j++];
		}
	}
	while (i < k)
	{
		pw[w++] = px[i++];
	}
	while (j < k)
	{
		pw[w++] = py[j++];
	}
}

void merge_sort(int* key, int size)
{
	int w[1000]; //此处有缺陷
	int count = 0;
	int go_on = 0;
	for (int k = 1; k < size; k *= 2)
	{
		for (int j = 0; j < size - k; j += 2 * k)
		{
			sort(key + j, key + j + k, w + j, k);
		}
		for (int i = 0; i < size; i++)
		{
			key[i] = w[i];
		}
		count++;
		if (count == 1)
		{
			printf("\n");
		}
		printf("\nthe %d array:", count);
		print_array(key, size, "");
		printf("\ninput any int to continue:");
		scanf("%d", &go_on);//用来演示排序过程
	}
}

int main()
{
	int a[] = { 51,652,45,12,5,11,541,58 };
	int size = sizeof(a) / sizeof(a[0]);
	print_array(a, size, "the 0 array:");
	merge_sort(a, size);
	print_array(a, size, "\nthe finnal array:");
	return 0;
}