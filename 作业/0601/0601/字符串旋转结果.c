#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <assert.h>
#include <string.h>

int is_left_move(char* before, char* after)
{
	assert(before && after);
	size_t len1 = strlen(before);
	size_t len2 = strlen(after);
	if (len1 != len2)
	{
		return 0;
	}
	strncat(before, before, len1);
	char* ret = strstr(before, after);
	if (ret == NULL)
	{
		return 0;
	}
	else
	{
		return 1;
	}
}

int main()
{
	char arr1[20] = "abcdef";
	char arr2[] = "cdefab";
	printf("%d", is_left_move(arr1, arr2));
	return 0;
}

//int find_num(char* s1, char* s2, int i)
//{
//	int sz = strlen(s1); //默认两个字母串的长度相等
//	for (; i < sz; i++)
//	{
//		if (*s1 == *(s2 + i))
//		{
//			return i;
//		}
//	}
//	return sz;
//}
//
//char* move_s(char* arr, int num)
//{
//	int i = 0, j = 0;
//	int sz = strlen(arr);
//	char temp = '0';
//	for (i = 0; i < num; i++)
//	{
//		for (j = 0; j < sz - 1; j++)
//		{
//			temp = *(arr + j);
//			*(arr + j) = *(arr + j + 1);
//			*(arr + j + 1) = temp;
//		}
//	}
//}
//
//int main()
//{
//	char s2[] = "BCAbA";
//	int reu = 1;
//	int sz = strlen(s2);
//	int key = 0;
//	while (reu != 0 && key < sz)
//	{
//		char s1[] = "AABCA";
//		key = find_num(s1, s2, key);
//		move_s(s1, sz - key);
//		reu = strcmp(s1, s2);
//		key++;
//	}
//	printf("%d", !reu);
//	return 0;
//}