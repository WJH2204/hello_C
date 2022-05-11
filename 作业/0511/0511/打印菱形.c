//#define _CRT_SECURE_NO_WARNINGS 1
//
//#include <stdio.h>
//
//int main()
//{
//	char arr[13][13] = { 0 };
//	int i = 0, j = 0, k = 0;
//	for (i = 0; i < 13; i++)
//	{
//		for (j = 0; j < 13; j++)
//		{
//			arr[i][j] = ' ';
//		}
//
//	}
//	for (i = 0; i <= 6; i++)
//	{
//		for (j = i, k = 6 - i; (j <= 6 + i) && (k <= 12 - i); )
//		{
//			arr[j][k] = '*';
//			k++;
//			j++;
//		}
//	}
//	for (i = 0; i < 13; i++)
//	{
//		for (j = 0; j < 13; j++)
//		{
//			printf("%c", arr[i][j]);
//		}
//		printf("\n");
//	}
//
//}