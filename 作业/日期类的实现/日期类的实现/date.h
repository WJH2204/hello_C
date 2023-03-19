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

	//����
	Date(int year = 1, int month = 1, int day = 1);

	//��������
	Date(const Date& d);

	//��ֵ��������� =
	Date& operator=(const Date& d);

	//��������� +=
	Date& operator+=(int day);

	//��������� +
	Date operator+(int day);

	//��������� -=
	Date& operator-=(int day);

	//��������� -
	Date operator-(int day);

	//ǰ�� ++
	Date& operator++();

	//���� ++
	Date operator++(int);

	//ǰ�� --
	Date& operator--();

	//���� --
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


