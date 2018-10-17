#include "Date.h"


Date::Date()
{
}

Date::~Date()
{
}

istream & operator>>(istream & in, Date & date)
{
	in >> date.day >> date.month >> date.year;
	return in;
}

ostream & operator<<(ostream & out, Date &date)
{
	out << date.day << " / " << date.month << " / " << date.year << endl;
	return out;
}
