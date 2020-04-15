//Муллов Игорь, 24 (7к) Шаблоны классов
#include "List.h"
#include "Pair.h"
#include <iostream>
using namespace std;
void main()
{
	setlocale(LC_ALL, "ru");
	List<int>A(5, 0);
	cout << "Ввод объекта А" << endl;
	cin >> A;
	cout << A << endl;
	List<int>B(10, 0);
	cout << "Объект В на 10 элементов, инициализированных нулями" << endl << B << endl;
	B = A;
	cout<<"Присваивание объекта А - объекту В"<<endl << B << endl;
	cout << "size:" << A() << endl;
	B = A + 10;
	cout<<"Операция сложения с константой"<<endl << B << endl;

	Pair p;
	cout << "Объект класса Pair"<<endl;
	cin >> p;
	cout << p;

	int k;
	cout << "Константа:"; cin >> k;
	Pair c;
	
	c = p + k;
	cout << "Операция сложения с константой" << endl << c << endl;

	List<Pair>a(3, p);
	cout << "Объект а через пользовательский тип данных Pair" << endl;
	cin >> a;
	cout<<"Вывод"<<endl << a << endl;
	cout << "size:" << a() << endl;
	List<Pair>b(5, p);
	cout<< "Объект b через пользовательский тип данных Pair" << endl << b << endl;
	b = a;
	cout<<"Операция присваивания объекта а - объекту b"<<endl << b << endl;
	cout<<"Второй элемент объекта а"<<endl << a[2] << endl;	
}