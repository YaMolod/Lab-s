//Муллов Игорь, 23 (6к) АТД. Контейнеры
#include "List.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");
	List a(5);
	cout << "Создаем объект а из 5 элементов, заполненный нулями" << endl;
	cout << a << endl;
	cout << "Заполняем значения элементов а, третий элемент инициализируем 100" << endl;
	cin >> a;
	a[2] = 100;
	cout << "Вывод а" << endl;
	cout << a << endl;
	List b(10);
	cout << "Создаем объект b из 10 элементов, заполненный нулями" << endl;
	cout << b << endl;
	cout << "Операция присваивания объекта а - объекту b" << endl;
	b = a;
	cout << b << endl;
	List c(10);
	cout << "Создаем объект с, увеличиваем значения b на 100 и присваиваем с" << endl;
	c = b + 100;
	cout << c << endl;
	cout << "Длина a:" << a() << endl;
	cout << "Ставим указатель на первый элемент а, выводим его" << endl;
	cout << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	cout << "Итерация указателя" << endl;
	cout << *i << endl;
	cout << "Вывод значений элементов а с помощью указателя" << endl;
	for (i = a.first(); i != a.last(); ++i)
	{
		cout << *i << " ";
	}
}