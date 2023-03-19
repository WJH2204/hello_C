#pragma once

#include <iostream>
#include <string>
using namespace std;

class Date
{
	friend ostream& operator<<(ostream& out, const Date& d);

	friend istream& operator>>(istream& in, Date& d);

public:

	int GetMonthDay(int year, int month);

	//构造
	Date(int year = 1, int month = 1, int day = 1);

	//拷贝构造
	Date(const Date& d);

	//赋值运算符重载 =
	Date& operator=(const Date& d);

	//运算符重载 +=
	Date& operator+=(int day);

	//重载运算符 +
	Date operator+(int day);

	//重载运算符 -=
	Date& operator-=(int day);

	//重载运算符 -
	Date operator-(int day);

	//前置 ++
	Date& operator++();

	//后置 ++
	Date operator++(int);

	//前置 --
	Date& operator--();

	//后置 --
	Date operator--(int);

	// >
	bool operator>(const Date& d);

	// ==
	bool operator==(const Date& d);

	// >=
	bool operator>=(const Date& d);

	// <
	bool operator<(const Date& d);

	// <=
	bool operator<=(const Date& d);

	// !=
	bool operator!=(const Date& d);

	// -
	int operator-(const Date& d);

	void print();

private:
	int _year;
	int _month;
	int _day;
};

inline ostream& operator<<(ostream& out, const Date& d)
{
	out << d._year << " " << d._month << " " << d._day;
	return out;
}

inline istream& operator>>(istream& in, Date& d)
{
	in >> d._year >> d._month >> d._day;
	return in;
}


