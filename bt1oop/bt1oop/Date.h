#pragma once
#include<iostream>
using namespace std;
class Date
{private:
	int day;
	int month;
	int year;
public:
	friend istream & operator>>(istream& in, Date&);
	friend ostream & operator<<(ostream & out, Date &);
	Date();
	~Date();
};

