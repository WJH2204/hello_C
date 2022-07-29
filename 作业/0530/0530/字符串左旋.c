//
//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//
//char* strleft(char* arr, int num)
//{
//	assert(arr);
//	int i = 0, j = 0;
//	char temp = '0';
//	int sz = strlen(arr);
//	num %= sz;
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j < sz - 1; j++)
//		{
//			temp = *(arr + j);
//			*(arr + j) = *(arr + j + 1);
//			*(arr + j + 1) = temp;
//		}
//	}
//	return arr;
//}
//
//int main()
//{
//	char arr[] = "abcd";
//	strleft(arr, 101);
//	printf("%s\n", arr);
//	return 0;
//}