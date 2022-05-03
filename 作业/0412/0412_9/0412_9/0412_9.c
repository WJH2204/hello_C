#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	scanf("%d %d", &a, &b);
	//辗转相除法
	while (a % b)
	{
		c = a % b;
		if (c == 1)
		{
			printf("两数互质");
			break;
		}
		a = b;
		b = c;
	}
	printf("%d", b);
	return 0;
}