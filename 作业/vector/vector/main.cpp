#include "vector.h"

int main()
{
	my::vector<int> v;
	v.push_back(1);
	v.push_back(2); 
	v.push_back(3); 
	v.push_back(4); 
	v.push_back(5); 
	v.push_back(6);
	v.push_back(7);

	my::vector<int>::const_reverse_iterator rit = v.crbegin();

	while (rit != v.crend())
	{
		cout << *rit << endl;
		++rit;
	}
	return 0;
}