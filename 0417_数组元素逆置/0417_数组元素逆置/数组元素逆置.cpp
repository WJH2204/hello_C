#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
using namespace std;

int main()
{
	int arr[] = { 1,2,3,4,5 };
	
	int start = 0;
	int tem = 0;
	int end = sizeof(arr) / sizeof(arr[0]) - 1;
	int i = 0;
	cout << "逆置前的元素：";
	for (i = 0; i < end + 1; i++)
	{
		 cout << arr[i] << " ";
	}
	cout << endl;
	for (start = 0; start < end ; start++, end--)
	{
		tem = arr[start];
		arr[start] = arr[end];
		arr[end] = tem;
	}
	cout << "逆置后的元素：";
	end = sizeof(arr) / sizeof(arr[0]) - 1;
	for (i = 0; i < end + 1; i++)
	{
		 cout << arr[i] << " ";
	}
	cout << endl;
	system("pause");

	return 0;
}