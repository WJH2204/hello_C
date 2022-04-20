#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

//int main()
//{
//	int num = 0;
//	cin >> num;
//	int max = num;
//	while (num != -1)
//	{
//		if (num > max)
//			max = num;
//		cin >> num;
//	}
//	cout << "the largest number is " << max << endl;
//	return 0;
//}

int main(void) {
    /* we will count the numbers here */
    int Evens = 0, Odds = 0;

    /* we will store the incoming numbers here */
    int Number;

    /* read first number */
    cin >> Number;

    /* 0 terminates execution */
    while (Number != 0) {
        /* check if the number is odd */
        if (Number % 2 == 1)
            /* increase ?odd¡± counter */
            Odds++;
        else
            /* increase ?even¡± counter */
            Evens++;
        /* read next number */
        cin >> Number;
    }
    /* print results */
    cout << "Even numbers: " << Evens << endl;
    cout << "Odd numbers: " << Odds << endl;
    return 0;
}