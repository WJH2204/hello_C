//#include <stdio.h>
//#include <assert.h>
//
//char* my_strncpy(char* destination, const char* source, size_t num)
//{
//	assert(destination && source);
//	char* ret = destination;
//	while (num)
//	{
//		if (*source == '\0')
//		{
//			break;
//		}
//		*destination++ = *source++;
//		num--;
//	}
//	while (num--)
//	{
//		*destination++ = '\0';
//
//	}
//	return ret;
//}
//
//int main()
//{
//	char arr1[20] = "123456789";
//	char arr2[] = "qqqq";
//	my_strncpy(arr1, arr2, 3);
//	printf(arr1);
//	return 0;
//}
