
#include <stdio.h>
#include <assert.h>

char* my_strcat(char* des, const char* sour)
{
	assert(des && sour);
	char* ret = des;
	while (*des != '\0')
	{
		des++;
	}
	while (*des++ = *sour++)
	{
		;
	}
	return ret;
}

int main()
{
	char arr1[20] = "abc ";
	char arr2[] = "def";
	printf("%s\n", my_strcat(arr1, arr2));
	return 0;
}