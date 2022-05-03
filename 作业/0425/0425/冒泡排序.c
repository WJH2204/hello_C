#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//函数声明
void bubble_sort(int* arr, int sz);
void swap(int* px, int* py);
void printarr(int* arr, int sz);


int main()
{
	int arr[] = { 0,2,6,45,15,26,4125,45,56,41,5,415,4,526 };
	//数组大小
	int sz = sizeof(arr) / sizeof(arr[0]);
	//调用冒泡排序函数
	bubble_sort(arr, sz);
	//打印输出
	printarr(arr, sz);
	return 0;
}

//冒泡排序函数
void bubble_sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++) //轮数
	{
		for (int j = 0; j < sz - 1 - i; j++) //每轮交换数
		{
			if (arr[j] > arr[j + 1])
				//调用交换函数
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

//交换函数
void swap(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

//打印数组函数
void printarr(int* arr, int sz)
{
	for(int i = 0; i < sz; i++, arr++)
	printf("%d ", *arr);
}

