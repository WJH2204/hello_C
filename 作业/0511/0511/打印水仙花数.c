//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//#include <math.h>
//
//int main()
//{
//	int i = 0, k = 0;
//	for (i = 0; i <= 100000; i++)
//	{
//		int sum = 0, j = 0, n = 0;
//		for (j = 0; ; j++)
//		{
//			if ((k = ((i / (int)pow(10, j)))) == 0)
//			{
//				n = j;
//				break;
//			}
//			
//		}
//		for (j = 0; j < n; j++)
//		{
//			k = (i / (int)pow(10, j)) % 10;
//			sum = sum + (int)pow(k, n);
//		}
//		if (sum == i)
//			printf("%d\n", i);
//	}
//	return 0;
//}