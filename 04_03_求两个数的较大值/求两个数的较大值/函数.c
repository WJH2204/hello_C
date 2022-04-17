#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int MAX(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}

int main()
{
	int num1 = 0;
	int num2 = 0;
	printf("请输入两个整数：");
	scanf("%d%d", &num1, &num2);
	int result = MAX(num1, num2);
	printf("较大值为%d", result);
	return 0;
}