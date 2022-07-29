//
//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//
//struct Stu
//{
//	char name[20];
//	int age;
//};
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
//		printf("%s", (arr+i)->name);
//		printf("%d\n", (arr+i)->age);
//	}
//	printf("\n");
//}
//
//int main()
//{
//	struct Stu arr[] = { {"zhangsan", 25}, {"zhangan", 30}, {"wangwu", 16}, {"andong", 35} };
//	qsort(arr, sizeof(arr) / sizeof(arr[1]), sizeof(arr[1]), cmp_by_name);
//	print_struct(arr, sizeof(arr) / sizeof(arr[1]));
//	qsort(arr, sizeof(arr) / sizeof(arr[1]), sizeof(arr[1]), cmp_by_age);
//	print_struct(arr, sizeof(arr) / sizeof(arr[1]));
//	return 0;
//}