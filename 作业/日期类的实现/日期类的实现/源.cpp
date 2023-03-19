#include "date.h"



int main()
{
	Date d1(2022, 10, 20);

	//d1.print();

	Date d2(d1);
	//d2.print();

	Date d3(1997, 2, 10);
	cin >> d3;
	cout << d3 << endl;

	Date d4(1996, 2, 10);

	//cout << (d3 - d4) << endl;

	//d4 = d3--;
	//

	//d3.print();
	//d4.print();


	//d3 -= 22;
	//d4 = d3 - 31;


	//d3.print();
	//d4.print();

	return 0;
}