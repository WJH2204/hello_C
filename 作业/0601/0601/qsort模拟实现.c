//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//void Swap(char*, char*, size_t);
//
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
//
//void bubble_sort(void* base, size_t num, size_t width, int(*compare)(const void* elem1, const void* elem2))
//{
//	int i = 0, j = 0;
//	for (i = 0; i < num - 1; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < num - 1 - i; j++)
//		{
//			if (compare((char*)base + j * width, (char*)base + (j + 1) * width) > 0)
//			{
//				flag = 0;
//				Swap((char*)base + j * width, (char*)base + (j + 1) * width, width);
//			}
//		}
//		if (flag == 1)
//		{
//			break;
//		}
//	}
//}
//
//void Swap(char* elem1, char* elem2, size_t width)
//{
//	int i = 0;
//	for (i = 0; i < width; i++)
//	{
//		char temp = *elem1;
//		*elem1 = *elem2;
//		*elem2 = temp;
//		elem1++;
//		elem2++;
//	}
//}
//
//
//int cmp_by_name(const void* elem1, const void* elem2)
//{
//	return strcmp(((struct Stu*)elem1)->name, ((struct Stu*)elem2)->name);
//}
//
//int cmp_by_age(const void* elem1, const void* elem2)
//{
//	return (((struct Stu*)elem1)->age - ((struct Stu*)elem2)->age);
//}
//
//void print_struct(struct Stu* arr, int num)
//{
//	int i = 0;
//	for (i = 0; i < num; i++)
//	{
//		printf("%s", (arr + i)->name);
//		printf("%d\n", (arr + i)->age);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	struct Stu arr[] = { {"zhangsan", 25}, {"zhangan", 30}, {"wangwu", 16}, {"andong", 35} };
//	bubble_sort(arr, sizeof(arr) / sizeof(arr[1]), sizeof(arr[1]), cmp_by_name);
//	print_struct(arr, sizeof(arr) / sizeof(arr[1]));
//	bubble_sort(arr, sizeof(arr) / sizeof(arr[1]), sizeof(arr[1]), cmp_by_age);
//	print_struct(arr, sizeof(arr) / sizeof(arr[1]));
//	return 0;
//}