//Муллов Игорь, 21 (4к) Наследование
#include "Person.h"
#include "Student.h"
#include <iostream>
using namespace std;

void f1(Person& p)
{
	p.set_name("Илья");
	cout << p;
}
Person f2()
{
	Student l("Максим", 19, 2020);
	return l;
}

void main()
{
	setlocale(LC_ALL, "ru");
	Person a;
	cout << "Объект a" << endl;
	cin >> a;
	cout << a;
	cout << "Операция присваивания" << endl;
	Person b("Игорь", 19);
	a = b;
	cout << a;
	cout << "Объект c" << endl;
	Student c;
	cin >> c;
	cout << c;
	cout << "Передача объекта класса Student " << endl;
	c.increase_year(3);
	cout << "Увеличение года на 3" << endl << c << endl;
	f1(c);
	a = f2();
	cout << "Присваивание объекту а - объекта класса Student" << endl;
	cout << a;
}