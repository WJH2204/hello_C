//
//#include <stdio.h>
//#include <assert.h>
//
//void* my_memcpy(void* des, void* sour, size_t num)
//{
//	assert(des && sour);
//	while (num--)
//	{
//		*((char*)des + num)  = *((char*)sour + num);
//	}
//	return des;
//}
//
//int main()
//{
//	int arr1[] = { 0,1,2,3,4 };
//	int arr2[5] = { 0 };
//	my_memcpy(arr2, arr1, 12);
//	int i = 0;
//	for (i = 0; i < 5; i++)
//	{
//		printf("%d ", arr2[i]);
//	}
//	return 0;
//}