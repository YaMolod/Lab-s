//������ �����, 23 (6�) ���. ����������
#include "List.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	List a(5);
	cout << "������� ������ � �� 5 ���������, ����������� ������" << endl;
	cout << a << endl;
	cout << "��������� �������� ��������� �, ������ ������� �������������� 100" << endl;
	cin >> a;
	a[2] = 100;
	cout << "����� �" << endl;
	cout << a << endl;
	List b(10);
	cout << "������� ������ b �� 10 ���������, ����������� ������" << endl;
	cout << b << endl;
	cout << "�������� ������������ ������� � - ������� b" << endl;
	b = a;
	cout << b << endl;
	List c(10);
	cout << "������� ������ �, ����������� �������� b �� 100 � ����������� �" << endl;
	c = b + 100;
	cout << c << endl;
	cout << "����� a:" << a() << endl;
	cout << "������ ��������� �� ������ ������� �, ������� ���" << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	cout << "�������� ���������" << endl;
	cout << *i << endl;
	cout << "����� �������� ��������� � � ������� ���������" << endl;
	for (i = a.first(); i != a.last(); ++i)
	{
		cout << *i << " ";
	}
}