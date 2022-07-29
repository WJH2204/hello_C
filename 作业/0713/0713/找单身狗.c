//#define _CRT_SECURE_NO_WARNINGS
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <errno.h>
//#include <assert.h>
//
//int compar(const void* p1, const void* p2)
//{
//	assert(p1 && p2);
//	return (*(int*)p1 - *(int*)p2);
//}
//
//int find_single(int* ptr, int num)
//{
//	assert(ptr);
//	static int j = 0;
//	while (j < num)
//	{
//		if (ptr[j] == ptr[j + 1])
//		{
//			j += 2;
//			continue;
//		}
//		int ret = ptr[j];
//		j++;
//		return ret;
//	}
//}
//
//
//int main()
//
//{
//	printf("ÇëÊäÈëÊý×Ö£º");
//	int capa = 3;
//	int* p = (int*)calloc(capa, 4);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
//
//	while (scanf("%d", p + i) == 1)
//	{
//		i++;
//		if (i == capa)
//		{
//			int* ps = (int*)realloc(p, 4 * (++capa));
//			if (ps == NULL)
//			{
//				printf("%s\n", strerror(errno));
//				return 1;
//			}
//			p = ps;
//		}
//	}
//	qsort(p, i, sizeof(p[0]), compar);
//
//
//	printf("%d\n", find_single(p, i));
//	printf("%d\n", find_single(p, i));
//
//	free(p);
//	p == NULL;
//	return 0;                                                                            
//}