#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int* odd_even(int* arr, const int size_arr)
{
	int i = 0, j = 0, k = 0;
	int arr_copy[50] = { 0 };
	for (i = 0; i < size_arr; i++)
	{
		if ((*(arr + i) % 2) == 0)
		{
			*(arr_copy + size_arr - 1 - j) = *(arr + i);
			j++;
		}
		else
		{
			*(arr_copy + k) = *(arr + i);
			k++;
		}
	}
	for (i = 0; i < size_arr; i++)
	{
		*(arr + i) = *(arr_copy + i);
	}
	return arr;
}

void print_arr(int* arr, int size_arr)
{
	int i;
	for (i = 0; i < size_arr; i++)
	{
		printf("%d ", *(arr + i));
	}

}

int main()
{
	int arr[] = { 3,1,2,3,4,5,6,7,8,9,10 };
	const int size_arr = sizeof(arr) / sizeof(arr[0]);
	print_arr(odd_even(arr, size_arr), size_arr);
	return 0;
}