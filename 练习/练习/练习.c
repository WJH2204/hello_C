#define _CRT_SECURE_NO_WARNINGS 1
///* A C program that has a function that prints
//a table of values for sineand cosine between(0, 1).*/
//
//#include<stdio.h>
//#include<math.h> /* has  sin(), cos() */
//int main(void)
//{
//	double param = 0.0;
//	int i = 0;
//	for (i = 1; i < 10; i++)
//	{
//		param = i / 10.0;
//		printf("sin( %lf ) = %lf\t", param, sin(param));
//		printf("cos( %lf ) = %lf\n", param, cos(param));
//	}
//	return 0;
//}

//#include <stdio.h>

//int main()
//{
//    int x = 0;
////    int y = 0;
////    scanf("%d", &x);
////    if (x < 0)
////    {
////        y = 1;
////        printf("%d", y);
////    }
////    else if (x == 0)
////    {
////        y = 0;
////        printf("%d", y);
////    }
////    else
////    {
////        y = -1;
////        printf("%d", y);
////    }
////
////    return 0;
////}
//
//
//#include <stdio.h>
//
//int main()
//{
//    int arr[8];
//    //输入生日信息
//    for (int i = 0; i < 8; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    //打印年
//    printf("year=");
//    for (int i = 0; i < 4; i++)
//    {
//        printf("%d", arr[i]);
//
//    }
//    //打印月
//    printf("month=");
//    for (int i = 4; i < 2; i++)
//    {
//        printf("%d", arr[i]);
//
//    }
//    //打印日
//    printf("day=");
//    for (int i = 0; i < 2; i++)
//    {
//        printf("%d", arr[i]);
//
//    }
//    return 0;
//}

//#include <stdio.h>
//int main(void)
//{
//    int y, m, d;
//    scanf("%4d%2d%2d", &y, &m, &d);
//    printf("year = %d\n", y);
//    printf("month = %02d\n", m);
//    printf("date = %02d\n", d);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int id_num = 0;
//    float score_c = 0;
//    float score_m = 0;
//    float score_e = 0;
//    scanf("%d;%f,%f,%f", &id_num, &score_c, &score_m, &score_e);
//    printf("The each subject score of No. %d is %f, %f, %f.", id_num, score_c, score_m, score_e);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    printf("\n%d", printf("Hello world!"));
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int arr[4];
//    scanf("%d %d %d %d", &arr[0], &arr[1], &arr[2], &arr[3]);
//    for (int i = 0; i < 3; i++)
//    {
//        int temp = arr[0];
//        if (arr[i] > arr[i + 1])
//        {
//            arr[i] = arr[i + 1]；
//                arr[i + 1] = temp;
//        }
//    }
//    printf("%d", arr[3]);
//    return 0;
//}

//#include <stdio.h>
//#define PI 3.1415926
//int main()
//{
//    float r = 0.0;
//    scanf("%f", &r);
//    float V = 4 / 3 * PI * r ^ 3;
//    printf("%03f", V);
//    return 0;
//}

//#include <stdio.h>
//#include <math.h>
//int main()
//{
//    float weight = 0.0, height = 0.0;
//    scanf("%f %f", &weight, &height);
//    float s = pow(height / 100, 2);
//    printf("%f", s);
//
//    printf("%0.2f", weight / pow(height/100, 2));
//    return 0;
//}
