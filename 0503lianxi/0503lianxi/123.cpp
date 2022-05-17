#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//#include <string>
//using namespace std;
//int main(void)
//{
//	string s = "Skipper", t = "Private";
//	int i = s.compare("Kowalski") > 0;
//	int j = s.compare("Rico") < 0;
//	cout << i + j << endl;
//	return 0;
//}

//class A {
//	int a;
//public:
//	A(void) { a = 1; }
//	int b(void) { return ++a; }
//};
//
//int main(void)
//{
//	A a;
//	a.b();
//	cout << a.b() << endl;
//	return 0;
//}

//class A {
//public:
//	int x;
//	void d() { x /= 2; }
//};
//class B : public A {
//public:
//	int y;
//	void d() { y /= 4; }
//};
//
//int main(void)
//{
//	B b;
//	b.x = b.y = 4;
//	b.d();
//	cout << b.x / b.y << endl;
//	return 0;
//}

//int main(void)
//{
//	int b = 4, * c = NULL, i = -1;
//	try {
//		c = new int[i];
//		b--;
//	}
//	catch (exception& e) {
//		c = new int[1];
//		b++;
//	}
//	cout << b << endl;
//	return 0;
//}

//enum e { a = 1, b, c, d };
//e& operator--(e& x) {
//	x = b; return x;
//}
//
//int main(void)
//{
//	e f = c;
//	cout << int(f--) << endl;
//	return 0;
//}

#include <stdio.h>

int main()
{
	//花两元买两瓶
	//两个空瓶换一瓶
	//再花一元买一瓶
	//得到两个空瓶再换一瓶
	//以此类推,等效于从除了第一次购买,之后的每次购买是一元买两瓶
	
	int num = 2;
	int i = 0;
	for (i = 2; i < 20; i++)
	{
		num = num + 2;
	}
	printf("%d", num);
	return 0;
}