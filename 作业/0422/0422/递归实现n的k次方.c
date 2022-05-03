#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>

float power(float n, float k)
{
	if (k > 0)
	{
		return n * power(n,k-1);
	}
	else if (k == 0)
	{
		return 1;
	}
	else
	{
		return 1.0 / power(n, -k);
	}
}

int main()
{
	float n = 0, k = 0;
	scanf("%f %f", &n, &k);
	float ret = power(n, k);
	printf("%f", ret);
	return 0;
}