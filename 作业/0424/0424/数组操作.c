#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

//��������
void init(int* arr, int sz);
void print(int* arr, int sz);
void reverse(int* arr, int sz);
void swap(int* px, int* py);


int main()
{
	int arr[] = { 5,2,4,6,8,15,6,41,58,4,1,5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	//��ӡ����
	print(arr, sz);
	printf("\n");
	//��������
	reverse(arr, sz);
	//��ӡ����
	print(arr, sz);
	printf("\n");
	//��ʼ������
	init(arr, sz);
	//��ӡ����
	print(arr, sz);
	return 0;
}

//��ʼ������
void init(int* arr, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		arr[i] = 0;
	}
}

//��ӡ���麯��
void print(int* arr, int sz)
{
	for (int i = 0; i < sz; i++, arr++)
		printf("%d ", *arr);
}

//��������
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

//����������Ԫ�ص�ֵ
void swap(int* px, int* py)
{
	int temp = *px;
	*px = *py;
	*py = temp;
}
