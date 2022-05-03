#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��������
void bubble_sort(int* arr, int sz);
void swap(int* px, int* py);
void printarr(int* arr, int sz);


int main()
{
	int arr[] = { 0,2,6,45,15,26,4125,45,56,41,5,415,4,526 };
	//�����С
	int sz = sizeof(arr) / sizeof(arr[0]);
	//����ð��������
	bubble_sort(arr, sz);
	//��ӡ���
	printarr(arr, sz);
	return 0;
}

//ð��������
void bubble_sort(int* arr, int sz)
{
	for (int i = 0; i < sz - 1; i++) //����
	{
		for (int j = 0; j < sz - 1 - i; j++) //ÿ�ֽ�����
		{
			if (arr[j] > arr[j + 1])
				//���ý�������
				swap(&arr[j], &arr[j + 1]);
		}
	}
}

//��������
void swap(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}

//��ӡ���麯��
void printarr(int* arr, int sz)
{
	for(int i = 0; i < sz; i++, arr++)
	printf("%d ", *arr);
}

