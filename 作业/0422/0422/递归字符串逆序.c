//#define _CRT_SECURE_NO_WARNINGS 1
//#include <stdio.h>
//
////º¯ÊýÉùÃ÷
//int my_strlen(int* arr);
//void reverse_string(char* string);
//
//int main()
//{
//	char arr[] = "abcdef";
//	reverse_string(arr);
//	printf("%s", arr);
//	return 0;
//}
//
////ÄæÐò×Ö·û´®º¯Êý
//void reverse_string(char* string)
//{
//	int sz = my_strlen(string);
//	int left = 0;
//	int right = sz - 1;
//	char temp = string[left];
//	string[left] = string[right];
//	string[right] = '\0';
//	if (right > 1)
//	{
//		reverse_string(string + 1);
//	}
//	string[right] = temp;
//}
//
////Çó×Ö·û´®³¤¶È
//int my_strlen(char* arr)
//{
//	int count = 0;
//	while (*arr != '\0')
//	{
//		count++;
//		arr++;
//	}
//	return count;
//}