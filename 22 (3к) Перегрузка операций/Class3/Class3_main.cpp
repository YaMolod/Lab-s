//������ �����, 22 (3�) ���������� ��������

#include "Class3.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");

	Pair a;
	Pair b;
	Pair c;
	cout << "���� ���������� a" << endl;
	cin >> a;
	cout << "���� ���������� b" << endl;
	cin >> b;
	++a;
	cout << "a=" << a;
	b++;
	cout << "b=" << b;
	cout << "a < b?\t";
	c = a < b;
	cout << " b > a?\t";
	c= b > a;
}

