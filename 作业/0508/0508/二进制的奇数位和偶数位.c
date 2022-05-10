//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
//int main()
//{
//	int a = 0, b = 0;
//	scanf("%d", &a);
//	int i = 0;
//	printf("binary\n");
//	for (i = 31; i >= 0; i--)
//	{
//		b = (a >> i) & 1;
//		printf("%d", b);
//	}
//	printf("\neven\n");
//	for (i = 31; i >= 0; i = i - 2)
//	{
//		b = (a >> i) & 1;
//		printf("%d", b);
//	}
//	printf("\nodd\n");
//	for (i = 30; i >= 0; i = i - 2)
//	{
//		b = (a >> i) & 1;
//		printf("%d", b);
//	}
//	return 0;
//}