#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//函数声明
void init(int* arr, int sz);
void print(int* arr, int sz);
void reverse(int* arr, int sz);
void swap(int* px, int* py);


int main()
{
	int arr[] = { 5,2,4,6,8,15,6,41,58,4,1,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//打印数组
	print(arr, sz);
	printf("\n");
	//逆置数组
	reverse(arr, sz);
	//打印数组
	print(arr, sz);
	printf("\n");
	//初始化数组
	init(arr, sz);
	//打印数组
	print(arr, sz);
	return 0;
}

//初始化数组
void init(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

//打印数组函数
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++, arr++)
		printf("%d ", *arr);
}

//逆置数组
void reverse(int* arr, int sz)
{
	int left = 0;
	int right = sz - 1;
	while (left < right)
	{
		swap(&arr[left], &arr[right]);
		left++;
		right--;
	}

}

//交换两数组元素的值
void swap(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
