//Муллов Игорь, 21 (5к)  Полиморфизм. Абстрактные классы. Виртуальные методы
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
	cout << "Переменная а типа Person" << endl;
	cin >> a;
	cout << a << endl;
	Object* p = &a;
	cout << "Ставим указатель на объект типа Person" << endl;
	v.add(p);
	p->Show();
	cout << "Переменная b типа Student" << endl;
	Student b;
	cin >> b;
	cout << b << endl;
	cout << "Ставим указатель на объект типа Student" << endl;
	p = &b;
	v.add(p);
	p->Show();
	cout << "Вывод вектора" << endl;
	cout << v;
}