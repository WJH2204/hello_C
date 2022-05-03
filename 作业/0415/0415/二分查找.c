//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int arr[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
//	int key = 77;
//	int left = 0;
//	int right = sizeof(arr) / sizeof(arr[0]) - 1;
//	int mid = (left + right) / 2;
//	while (left <= right)
//	{
//		if (arr[mid] < key)
//		{
//			left = mid + 1;
//			mid = (left + right) / 2;
//		}
//		else if (arr[mid] > key)
//		{
//			right = mid - 1;
//			mid = (left + right) / 2;
//		}
//		else
//		{
//			printf("%d", mid);
//			return 0;
//		}
//	}
//	printf("’“≤ªµΩ°£");
//	return 0;
//}