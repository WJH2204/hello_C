//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncat(char* des, const char* sour, size_t num)
//{
//	assert(des && sour);
//	char* ret = des;
//	while (*des != '\0')
//	{
//		des++;
//	}
//	while (num--)
//	{
//		if (*sour == '\0')
//		{
//			break;
//		}
//		*des++ = *sour++;
//	}
//	*des = '\0';
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "abc ";
//	char arr2[] = "def";
//	printf(my_strncat(arr1, arr2, 5));
//	return 0;
//}