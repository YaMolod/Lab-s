//������ �����, 24 (7�) ������� �������
#include "List.h"
#include "Pair.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	List<int>A(5, 0);
	cout << "���� ������� �" << endl;
	cin >> A;
	cout << A << endl;
	List<int>B(10, 0);
	cout << "������ � �� 10 ���������, ������������������ ������" << endl << B << endl;
	B = A;
	cout<<"������������ ������� � - ������� �"<<endl << B << endl;
	cout << "size:" << A() << endl;
	B = A + 10;
	cout<<"�������� �������� � ����������"<<endl << B << endl;

	Pair p;
	cout << "������ ������ Pair"<<endl;
	cin >> p;
	cout << p;

	int k;
	cout << "���������:"; cin >> k;
	Pair c;
	
	c = p + k;
	cout << "�������� �������� � ����������" << endl << c << endl;

	List<Pair>a(3, p);
	cout << "������ � ����� ���������������� ��� ������ Pair" << endl;
	cin >> a;
	cout<<"�����"<<endl << a << endl;
	cout << "size:" << a() << endl;
	List<Pair>b(5, p);
	cout<< "������ b ����� ���������������� ��� ������ Pair" << endl << b << endl;
	b = a;
	cout<<"�������� ������������ ������� � - ������� b"<<endl << b << endl;
	cout<<"������ ������� ������� �"<<endl << a[2] << endl;	
}