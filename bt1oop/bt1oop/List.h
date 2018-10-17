#pragma once
#include<iostream>
#include"NhanVien.h"
using namespace std;
class List
{
private:
	NhanVien *InfNv;
	int quantity;

public:
	void search(int);
	void Merge(int, int, int);
	void MergeSort(int, int);
	friend istream &operator >>(istream &in, List &);
	friend ostream & operator<<(ostream & out, List);
	NhanVien operator[](const int i);
	List();
	~List();
	void menu(List &ql);
	void AddBegin(NhanVien);
	void AddEnd(NhanVien);
	void add(NhanVien,int);
	void delBegin();
	void delEnd();
	void del(int s);
	void update(string );
};

