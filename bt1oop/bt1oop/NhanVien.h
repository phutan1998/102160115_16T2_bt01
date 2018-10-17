#pragma once
#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class NhanVien
{private:
	string name;
	string MaNv;
	Date date;
	bool gender;
	double salary;
public:
	NhanVien();
	~NhanVien();
	void setMaNv(string);
	void setName(string);
	void setDate(Date);
	void setGender(bool);
	void setSalary(double);
	string getMaNv();
	double getSalary();
	friend istream & operator>>(istream & in, NhanVien &);
	friend ostream & operator<<(ostream & out, NhanVien);
};

