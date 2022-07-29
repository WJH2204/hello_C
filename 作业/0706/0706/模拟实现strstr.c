//
//#include <stdio.h>
//#include <assert.h>
//
//char* my_strstr(const char* string, const char* strCharSet)
//{
//	assert(string && strCharSet);
//	char* big = string;
//	char* small = strCharSet;
//	char* re_start = string;
//	while (*big != '\0')
//	{
//		big = re_start;
//		small = strCharSet;
//		while (*big != '\0' && *small != '\0' && *big == *small)
//		{
//			big++;
//			small++;
//		}
//		if (*small == '\0')
//		{
//			return re_start;
//		}
//		else
//		{
//			re_start++;
//		}
//	}
//	return NULL;
//
//}
//
//int main()
//{
//	char str1[] = "wangjjjjjjinhai";
//	char str2[] = "jin";
//	char* ret = my_strstr(str1, str2);
//	if (ret == NULL)
//	{
//		printf("No Str");
//	}
//	else
//	{
//		printf("%s\n", ret);
//	}
//	return 0;
//}