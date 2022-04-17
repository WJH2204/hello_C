// ³Ë·¨¿Ú¾÷±í
#include <iostream>

using namespace std;

int main()
{
	int i = 0;
	int j = 0;
	for (i = 1; i < 10; i++)
	{
		for (j = 1; j <= i; j++)
		{
			cout << j << "*" << i << "=" << j * i << "\t";
		}
		cout << endl;
	}

	system("pause");

	return 0;
}