#include "NhanVien.h"

NhanVien::NhanVien()
{
}

NhanVien::~NhanVien()
{
}

void NhanVien::setMaNv(string x)
{
	this->MaNv = x;
}

void NhanVien::setName(string x)
{
	this->name = x;
}

void NhanVien::setDate(Date date)
{
	
	this->date = date;
}

void NhanVien::setGender(bool x)
{
	this->gender = x;
}

void NhanVien::setSalary(double x)
{
	this->salary = x;
}

string NhanVien::getMaNv()
{
	return this->MaNv;
}

double NhanVien::getSalary()
{
	return this->salary;
}

istream & operator>>(istream & in, NhanVien & n)
{
	int choose;
	
	
	do {
		cout << "Enter ma nhan vien:";
		in >> n.MaNv;
		if (n.MaNv.length() >= 8) {
			cout << "Enter again." << endl;
		}

	} while (n.MaNv.length() >= 8);
	cin.ignore();
	cout << "Enter ten:";
	getline(in, n.name);
	cout << "Enter ngay :";
	in >> n.date;
	cout << "Chon gioi tinh:" << endl;
	cout << "1.Nam" << endl;
	cout << "2.Nu" << endl;
	cout << "Lua Chon Cua Ban la:";
	
	do {
		in >> choose;
		if (choose == 1) {
			n.gender = true;
		}
		if (choose == 2) {
			n.gender = false;
		}
		if (choose != 1 && choose != 2) {
			cout << "Enter again." << endl;
		}
	} while (choose != 1 && choose != 2);
	
	cout << "Enter luong :";
	in >> n.salary;
	return in;
}

ostream & operator<<(ostream & out, NhanVien n )
{
	
	out <<"MaNV:"<< n.MaNv << endl;
	out << "Name:" << n.name << endl;
	out << "Date:" << n.date ;
	if (n.gender == true) {
		out << "Gender:Nam"<< endl;
	}
	if (n.gender == false) {
		out << "Gender:Nu"<< endl;
	}
	out << "Luong:" << n.salary << endl;
	out << "**********************************"<<endl;
	return out;
}
