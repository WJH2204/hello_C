#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<math.h>
int main(void)
{

    float interval, x, y;
    int(i);
    for (i = 0; i < 10; i++)
    {
        interval = i / 10.0;
        x = sin(interval);
        y = cos(interval);
        printf("sin(%f)=%f\t cosine(%f)=%f\n", interval, x, interval, y);
    }
    return 0;
}