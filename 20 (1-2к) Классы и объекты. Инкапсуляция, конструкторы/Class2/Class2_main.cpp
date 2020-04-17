#include "Class2.h"
#include <iostream>
#include <string>
using namespace std;

Cvitancia make_cvitancia()
{
	int i;
	string s;
	double d;
	cout << "¬ведите номер:";
	cin >> i;
	cout << "¬ведите дату:";
	cin >> s;
	cout << "¬ведите стоимость:";
	cin >> d;
	Cvitancia t(i, s, d);
	return t;
}

void print_cvitancia(Cvitancia t)
{
	t.show();
}

void main()
{
	setlocale(LC_ALL, "ru");
	Cvitancia t1;
	t1.show();
	Cvitancia t2(10, "02.04.20", 32222);
	t2.show();
	Cvitancia t3 = t2;
	t3.set_number(28);
	t3.set_date("30.03.01");
	t3.set_cost(6666);
	print_cvitancia(t3);
	t1 = make_cvitancia();
	t1.show();
}