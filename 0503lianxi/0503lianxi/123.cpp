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

//#include <stdio.h>
//
//int main()
//{
//	//花两元买两瓶
//	//两个空瓶换一瓶
//	//再花一元买一瓶
//	//得到两个空瓶再换一瓶
//	//以此类推,等效于从除了第一次购买,之后的每次购买是一元买两瓶
//	
//	int num = 2;
//	int i = 0;
//	int money = 0;
//	scanf("%d", &money);
//	for (i = 2; i < money; i++)
//	{
//		num = num + 2;
//	}
//	printf("%d", num + 1);//最后一次的两个空瓶还可以换一瓶，所以+1
//	return 0;
//}



//#include <stdio.h>
//
//void merge(int* arr, int* arr_n, int* arr_m, int n, int m)
//{
//    int i = 0, j = 0, k = 0;
//    for (i = 0, j = 0, k = 0; i < n || j < m; )
//    {
//        if (i == n)
//        {
//            arr + k = arr_m + j;
//        }
//        else if (j == m)
//        {
//            arr + k = arr_n + i;
//        }
//        else
//        {
//            if (*(arr_n + i) > *(arr_m + j))
//            {
//                *(arr + k) = *(arr_m + j);
//                j++;
//            }
//            else
//            {
//                *(arr + k) = *(arr_n + i);
//                i++;
//            }
//            k++;
//        }
//    }
////}
//
//int main()
//{
//    int n = 0, m = 0;
//    int arr_n[1000], arr_m[1000], arr[2000];
//    scanf("%d %d", &n, &m);
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", arr_n + i);
//    }
//    for (i = 0; i < m; i++)
//    {
//        scanf("%d", arr_m + i);
//    }
//    merge(arr, arr_n, arr_m, n, m);
//    for (i = 0; i < n + m; i++)
//    {
//        printf("%d ", *(arr + i));
//    }
//    return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    int i = 0, j = 0;
//    int a = scanf("%d", &n);
//    while (scanf("%d", &n))
//    {
//        for (i = 0; i < n; i++)
//        {
//            //打印空格
//            for (j = 0; j < n - 1 - i; j++)
//            {
//                printf("  ");
//            }
//            //打印星号
//            for (; j < n; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//
//    return 0;
//}


/*
* 0000 0000 0000 0000 0000 0000 1100 1000  //200
* 0000 0000 0000 0000 0000 0000 0110 0100  //100
* 
* 
* 1111 1111 1111 1111 1111 1111 0111 1111 //-129不嘛
*                               0111 1111 //arr[128] 127
* 1111 1111 1111 1111 1111 1111 0111 1110
*                               0111 1110 //arr[129] 126

































*/

#include <stdio.h>
int main()
{
    int a = 0x1234;
    return 0;
}




