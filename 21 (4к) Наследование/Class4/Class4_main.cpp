//������ �����, 21 (4�) ������������
#include "Person.h"
#include "Student.h"
#include <iostream>
using namespace std;

void f1(Person& p)
{
	p.set_name("����");
	cout << p;
}
Person f2()
{
	Student l("������", 19, 2020);
	return l;
}

void main()
{
	setlocale(LC_ALL, "ru");
	Person a;
	cout << "������ a" << endl;
	cin >> a;
	cout << a;
	cout << "�������� ������������" << endl;
	Person b("�����", 19);
	a = b;
	cout << a;
	cout << "������ c" << endl;
	Student c;
	cin >> c;
	cout << c;
	cout << "�������� ������� ������ Student " << endl;
	c.increase_year(3);
	cout << "���������� ���� �� 3" << endl << c << endl;
	f1(c);
	a = f2();
	cout << "������������ ������� � - ������� ������ Student" << endl;
	cout << a;
}