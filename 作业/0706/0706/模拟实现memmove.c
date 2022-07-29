

#include <stdio.h>
#include <assert.h>

void* my_memmove(void* des, void* sour, size_t num)
{
	assert(des && sour);
	if (des >= sour)
	{
		while (num--)
		{
			*((char*)des + num) = *((char*)sour + num);
		}
	}
	else
	{
		int i = 0;
		for (i = 0; i < num; i++)
		{
			*((char*)des + i) = *((char*)sour + i);
		}
	}
	return des;
}

int main()
{
	int arr1[] = { 0,1,2,3,4,5,6,7,8,9 };
	my_memmove(arr1+2, arr1+4, 20);
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		printf("%d ", arr1[i]);
	}
	return 0;
}