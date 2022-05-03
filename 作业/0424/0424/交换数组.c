//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//void swaparr(arrA, szA, arrB, szB);
//void printarr(int* arr, int sz);
//
//
//int main()
//{
//	int arrA[5] = { 1,2,3,4,5 };
//	int arrB[5] = { 5,4,3,2,1 };
//	int sz = sizeof(arrA) / sizeof(arrA[0]); //数组大小
//	swaparr(arrA, arrB, sz);
//	printarr(arrA, sz);
//	printf("\n");
//	printarr(arrB, sz);
//	return 0;
//}
//
////交换数组对应元素
//void swaparr(int* arrA, int* arrB, int sz)
//{
//	for (int i = 0; i < sz; i++)
//	{
//		int temp = arrA[i];
//		arrA[i] = arrB[i];
//		arrB[i] = temp;
//	}
//}
//
////打印数组函数
//void printarr(int* arr, int sz)
//{
//	for (int i = 0; i < sz; i++, arr++)
//		printf("%d ", *arr);
//}
