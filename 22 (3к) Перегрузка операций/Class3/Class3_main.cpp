//ћуллов »горь, 22 (3к) ѕерегрузка операций

#include "Class3.h"
#include <iostream>
using namespace std;

void main()
{
	setlocale(LC_ALL, "ru");

	Pair a;
	Pair b;
	Pair c;
	cout << "¬вод переменной a" << endl;
	cin >> a;
	cout << "¬вод переменной b" << endl;
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

