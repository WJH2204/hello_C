#define _CRT_SECURE_NO_WARNINGS 1


//A program that can give the sine of a value between 0 and 1 (non inclusive).
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	double param, result;
//	printf("Please enter parameters:");
//	scanf("%lf", &param);
//	result = sin(param);
//	if (result > 0 && result < 1)
//		printf("The sine of %f is %f.\n", param, result);
//	return 0;
//}

//阶乘
//#include <stdio.h>
//
//int main()
//{
//	int j = 1;
//	int s = 1;
//	int sum = 0;
//	for (j = 1; j < 11; j++)
//	{
//		s = s * j;
//		sum += s;
//	}
//	printf("结果为%d。", sum);
//	return 0;
//}

////查找有序数组的某个元素
//#include <stdio.h>
//int main()
//{
//	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
//	printf("请输入您要查找的数字：");
//	int k = 0;
//	scanf("%d", &k);
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int left = 0;
//	int right = sz - 1;
//	int mid = (left + right) / 2;
//	for (; arr[mid] != k; )
//	{
//		if (arr[mid] > k)
//		{
//			right = mid - 1;
//		}
//		else
//		{
//			left = mid + 1;
//		}
//		mid = (left + right) / 2;
//	}
//	printf("arr[%d] = %d", mid, k);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 17 / 2;
//	printf("%d", a);
//	return 0;
//}

//#include <stdio.h>

//int main()
//{
//	int i = 1;
//	while (i <= 100)
//	{
//		if (i % 2 == 1)
//			printf("%d ", i);
//		i++;
//	}
//	return 0;
//}

#include <stdio.h>

int main()
{
	int i = 0;
	scanf("%d", &i);
	switch (i)
	{
	case(1):
			printf("1");
			break;
	default:
			printf("0");
			break;
	case(2):
			printf("1");
			break;
	case(3):
			printf("1");
			break;

	}
	return 0;
}