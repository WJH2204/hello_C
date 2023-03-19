#include "date.h"

int Date::GetMonthDay(int year, int month)
{
	int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 &&
		( (year % 4 == 0 && year % 100 != 0) || year % 400 == 0))
	{
		return 29;
	}
	return day[month];
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;

	if ( !(_year >= 1 &&
		(_month >= 1 && _month <= 12) &&
		(_day >= 1 && _day <= GetMonthDay(_year, _month))) )
	{
		cout << "Illegal date" << endl;
	}
}

Date::Date(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;
}

Date& Date::operator=(const Date& d)
{
	if (this != &d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	return *this;
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		_month++;
		while (_month > 12)
		{
			_month = 1;
			_year++;
		}
	}

	return *this;
}

Date Date::operator+(int day)
{
	Date ret(*this);
	ret += day;
	return ret;
}

Date& Date::operator-=(int day)
{
	_day -= day;
	while (_day < 1)
	{
		_month--;
		while (_month < 1)
		{
			_month = 12;
			_year--;
		}
		_day += GetMonthDay(_year, _month);

	}

	return *this;
}

Date Date::operator-(int day)
{
	Date ret(*this);
	ret -= day;
	return ret;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date ret(*this);
	*this += 1;
	return ret;
}

Date& Date::operator--()
{
	*this -= 1;
	return *this;
}

Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
		return true;
	if (_year == d._year && _month > d._month)
		return true;
	if (_year == d._year && _month == d._month && _day > d._day)
		return true;

	return false;
}

bool Date::operator==(const Date& d)
{
	if (_year == d._year && _month == d._month && _day == d._day)
		return true;

	return false;
}

bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

int Date::operator-(const Date& d)
{
	int ret = 0;

	Date d1(*this);
	Date d2(d);
	int flag = 1;

	if (d2 > d1)
	{
		d1 = d;
		d2 = *this;
		flag = -1;
	}

	ret += d1._day - d2._day;
	d1._day -= ret;
	while (d1 != d2)
	{
		d1._month--;
		if (d1._month == 0)
		{
			d1._month = 12;
			d1._year--;
		}
		ret += GetMonthDay(d1._year, d1._month);
	}

	return ret * flag;

}

void Date::print()
{
	cout << _year << "/" << _month << "/" << _day << endl;
}