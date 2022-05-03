#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int leap_year(int a)
{
	if ((a % 4 == 0 && a % 100 != 0) || a % 400 == 0)
		return 1;
	return 0;
}

int main()
{
	int year = 0;
	scanf("%d", &year);
	printf("%d", leap_year(year));//0不是闰年，1是闰年
	return 0;
}