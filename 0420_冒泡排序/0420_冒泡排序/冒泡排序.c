#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

int main()
{
	int arr[] = { 8, 54, 9, 57, 7, 32, 4751, 74, 61 };
	//求数组元素个数
	int sz = sizeof(arr) / sizeof(arr[0]);
	//打印排序前
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	//交换顺序
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = 0; j < sz -i - 1; j++)
		{
			int tem = arr[j];
			if (arr[j] < arr[j+1])
					;
			else
			{
				arr[j] = arr[j+1];
				arr[j+1] = tem;
			}
		}
	}
	//打印排序后
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}