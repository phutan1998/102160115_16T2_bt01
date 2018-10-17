#include "List.h"

List::List()
{
}


List::~List()
{
}
void List::search(int salary) 
{
	int left = 0, right = this->quantity - 1;
	int mid;
	bool kt = false;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (salary == (this->InfNv + mid)->getSalary())
		{
			cout << "Found." << endl;
			cout << *(this->InfNv + mid);
			system("pause");
			kt = true;
		}
		if (salary > (this->InfNv + mid)->getSalary()) left = mid + 1;
		else right = mid - 1;
	}
	if (kt == false)
	{
		cout << "Not found." << endl;
		system("pause");
	}
}

void List::Merge(int left, int mid, int right)
{
	NhanVien *temp; 
	int i = left; 
	int j = mid + 1; 

	temp = new NhanVien[right - left + 1]; 

	for (int k = 0; k <= right - left; k++)
	{
		
		if ((*(this->InfNv + i)).getSalary() < (*(this->InfNv + j)).getSalary())
		{
			
			temp[k] = *(this->InfNv + i);
			i++; 
		}
		else 
		{
			temp[k] = *(this->InfNv + j);
			j++; 
		}

		
		if (i == mid + 1)
		{
			
			while (j <= right)
			{
				k++;
				temp[k] = *(this->InfNv + j);
				j++;
			}
			break;
		}

		
		if (j == right + 1)
		{
			
			while (i <= mid)
			{
				k++;
				temp[k] = *(this->InfNv + i);
				i++;
			}
			break;
		}
	}

	for (int k = 0; k <= right - left; k++)
		*(this->InfNv + (left + k)) = temp[k];

}

void List::MergeSort(int left, int right)
{
	if (right > left)
	{
		int mid; 
		mid = (left + right) / 2;
		MergeSort(left, mid); 
		MergeSort(mid + 1, right); 
		Merge(left, mid, right); 
	}
}

NhanVien List::operator[](const int i)
{
	return *(this->InfNv + i);
}

istream & operator>>(istream & in, List & l)
{
	
	cout << "Enter so luong nhan vien: ";
	in >> l.quantity;
	l.InfNv = new NhanVien[l.quantity];
	for (int i = 0; i <= l.quantity - 1; i++) {
		NhanVien c;
		cout << "Enter thong tin nhan vien so " << i+1 <<": "<< endl;
		in >> c; 
		l.InfNv[i] = c;

	}
	return in;
}

ostream & operator<<(ostream & out, List l)
{
	system("cls");
	for (int i = 0; i < l.quantity; i++) {
		out << "Nhan vien so " << i + 1 <<": "<< endl;
			out << l.InfNv[i] << endl;

	}
	return out;
}

void List::delBegin()
{
	NhanVien * c;
	c = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		c[i] = this->InfNv[i];

	}
	delete[]this->InfNv;
	
	this->quantity--;
	this->InfNv = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		this->InfNv[i] = c[i + 1];
	}
}
void List::delEnd()
{
	NhanVien *c;
	c = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		c[i] = this->InfNv[i];
	}
	delete[]this->InfNv;
	this->quantity--;
	this->InfNv = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		this->InfNv[i] = c[i];
	}
}

void List::del(int s)
{
	int b = s - 1;
	NhanVien *c;
	c = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		c[i] = this->InfNv[i];
	}
	delete[]this->InfNv;
	this->quantity--;
	this->InfNv = new NhanVien[this->quantity];
	for (int i = 0; i < b; i++) {
		this->InfNv[i] = c[i];
	}
	for (int i = b; i < this->quantity; i++) {
		this->InfNv[i] = c[i + 1];
	}

}

void List::AddBegin(NhanVien a) {
	NhanVien *n;
	n = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		n[i] = this->InfNv[i];

	}
	delete[]this->InfNv;
	this->quantity++;
	this->InfNv = new NhanVien[this->quantity];
	this->InfNv[0] = a;
	for (int i = 1; i < this->quantity; i++) {
		this->InfNv[i] = n[i - 1];
	}
}
void List::AddEnd(NhanVien b) {
	NhanVien *n;
	n = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		n[i] = this->InfNv[i];

	}
	delete[]this->InfNv;
	this->quantity++;
	this->InfNv = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity - 1; i++) {
		this->InfNv[i] = n[i];
	}
	this->InfNv[this->quantity - 1] = b;
}
void List::add(NhanVien c, int s) {
	int b = s - 1;
	NhanVien *n;
	n = new NhanVien[this->quantity];
	for (int i = 0; i < this->quantity; i++) {
		n[i] = this->InfNv[i];
	}
	delete[]this->InfNv;
	this->quantity++;
	this->InfNv = new NhanVien[this->quantity];
	for (int i = 0; i < b; i++) {
		this->InfNv[i] = n[i];
	}
	this->InfNv[b] = c;
	for (int i = b + 1; i < this->quantity; i++) {
		this->InfNv[i] = n[i - 1];
	}

}

void List::update(string s)
{
	for (int i = 0; i < this->quantity; i++) {
		if (this->InfNv[i].getMaNv() == s) {
			int choose;
			do {
				
				cout << "\n1.Thay doi ma nhan vien: " << endl;
				cout << "2.Thay doi ten." << endl;
				cout << "3.Thay doi ngay." << endl;
				cout << "4.Thay doi gioi tinh." << endl;
				cout << "5.Thay doi luong." << endl;
				cin >> choose;
				if (choose == 1) {
					string s;
					cout << "Enter  ma nhan vien moi.";
					cin >> s;
					this->InfNv[i].setMaNv(s);
				}
				if (choose == 2) {
					string s;
					cout << "Enter ten moi";
					cin >> s;
					this->InfNv[i].setName(s);
				}
				if (choose ==3 ) {
					Date date;
					cout << "Enter ngay moi";
					cin >> date;
					this->InfNv[i].setDate(date);
				}
				if (choose == 4) {
					bool b;
					cout << "Enter gioi tinh moi.";
					cin >> b;
					this->InfNv->setGender(b);
				}
				if (choose == 5) {
					double d;
					cout << "Enter luong moi";
					cin >> d;
					this->InfNv[i].setSalary(d);
				}
				if (choose<1 || choose>5) {
					cout << "Enter again.";
				}
				

			} while (choose < 1 || choose>5);
		}
		else {
			cout << "Khong tim thay";
		}
	}
}
void List::menu(List &ql)
{
	int choose;

	do {
		cout << "***************MENU***************" << endl;
		cout << "         1. Nhap danh sach." << endl;
		cout << "         2. Xuat danh sach." << endl;
		cout << "         3. Them." << endl;
		cout << "         4. Xoa." << endl;
		cout << "         5. Cap nhat." << endl;
		cout << "         6. Sap xep." << endl;
		cout << "         7. Tim kiem." << endl;
		cout << "         8. Thoat." << endl;
		cout << "**********************************" << endl;
		cout << "Enter lua chon: ";
		cin >> choose;
		switch (choose)
		{
		case 1: {
			cin >> *this; break;
		}
		case 2: {
			cout << *this; break;
		}
		case 3: {
			int chon;
			do {

				cout << "1.Them Vi Tri Dau " << endl;
				cout << "2.Them Vi Tri Cuoi " << endl;
				cout << "3.Them Vi Tri Bat Ky " << endl;
				cin >> chon;
				if (chon == 1) {
					NhanVien a;
					cin >> a;
					this->AddBegin(a);
				}
				if (chon == 2) {
					NhanVien b;
					cin >> b;
					this->AddEnd(b);
				}
				if (chon == 3) {
					int i;
					cout << "Nhap Vao Vi Tri Can Them";
					cin >> i;
					NhanVien c;
					cin >> c;
					this->add(c, i);
				}
				if (chon < 1 || chon > 3) {
					cout << "Moi Ban Nhap Lai";

				}
			} while (chon < 1 || chon > 3);

			break;

		}
		case 4: {
			int choose;
			do {
				cout << "1.Xoa Vi Tri Dau" << endl;
				cout << "2.Xoa Vi Tri Cuoi" << endl;
				cout << "3.Xoa Vi Tri Bat Ky" << endl;
				cin >> choose;
				if (choose == 1) {
					this->delBegin();
				}
				if (choose == 2) {
					this->delEnd();
				}
				if (choose == 3) {
					int s;
					cout << "Chon Vi Tri Ban Muon Xoa :";
					cin >> s;
					this->del(s);
				}
				if (choose < 1 || choose >3) {
					cout << "Enter again";
				}

			} while (choose < 1 || choose>3);
			break;
		}
		case 5: {
			string s;
			cout << "Nhap Ma Nhan Vien Ban Muon Cap Nhat :";
			cin >> s;
			this->update(s);
			break;
		}
		case 6: {
			ql.MergeSort(0, ql.quantity - 1);
			break;
		}

		case 7: {
			double luong;
			cout << "Enter luong ban muon tim kiem: ";
			cin >> luong;
			ql.search(luong);
			break;
		}
		case 8: {
			break;
		}

				if (choose < 1 || choose >8) {
					cout << "Enter again." << endl;

				}

		}
	} while (true);
}
