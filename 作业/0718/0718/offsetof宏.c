//
//#include <stdio.h>
//
//struct S
//{
//	char a;
//	int b;
//	char c;
//	int d;
//};
//
//#define Offsetof(type, member) (size_t)&(((type*)0)->member)
//
//int main()
//{
//	printf("%zu\n", Offsetof(struct S, a));
//	printf("%zu\n", Offsetof(struct S, b));
//	printf("%zu\n", Offsetof(struct S, c));
//	printf("%zu\n", Offsetof(struct S, d));
//
//	return 0;
//}