//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//
//int fibclose(int n)
//{
//	int f0 = 0;
//	int f1 = 1;
//	int f2 = f0;
//	while (f2 - n < 0)
//	{
//		f2 = f1 + f0;
//		f0 = f1;
//		f1 = f2;
//	}
//	return f2 - n < n - f0 ? f2 - n : n - f0;
//}
//
//
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int ret = fibclose(n);
//	printf("%d", ret);
//	return 0;
//}