//������ �����, 21 (5�)  �����������. ����������� ������. ����������� ������
#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include <iostream>
#include <string>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	Vector v(5);
	Person a;
	cout << "���������� � ���� Person" << endl;
	cin >> a;
	cout << a << endl;
	Object* p = &a;
	cout << "������ ��������� �� ������ ���� Person" << endl;
	v.add(p);
	p->Show();
	cout << "���������� b ���� Student" << endl;
	Student b;
	cin >> b;
	cout << b << endl;
	cout << "������ ��������� �� ������ ���� Student" << endl;
	p = &b;
	v.add(p);
	p->Show();
	cout << "����� �������" << endl;
	cout << v;
}