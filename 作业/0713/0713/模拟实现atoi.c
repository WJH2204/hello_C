
#include <stdio.h>
#include <ctype.h>
#include <assert.h>
#include <limits.h>

int my_atoi(const char* str)
{
	assert(str);
	while (isspace(*str) != 0 && *str != '\0')
	{
		str++;
	}
	int sign = 1;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else if (*str == '+')
	{
		str++;
	}
	long long sum = 0;
	while (*str != '\0' && isdigit(*str))
	{
		sum = (*str - '0') * sign + sum * 10;
		str++;
		if (sum > INT_MAX)
		{
			return INT_MAX;
		}
		if (sum < INT_MIN)
		{
			return INT_MIN;
		}
	}
	return sum;
	
}

int main()
{
	char arr[] = "  -137abc";
	printf("%d\n", my_atoi(arr));
	return 0;
}