#include "Class2.h"
#include <iostream>
#include <string>
using namespace std;

Cvitancia::Cvitancia()
{
	number = 0;
	date = "";
	cost = 0;
	cout << "Конструктор без параметров для объекта:" << this << endl;
}

Cvitancia::Cvitancia(int n, string d, double c)
{
	number = n;
	date = d;
	cost = c;
	cout << "Конструктор с параметрами для объекта:" << this << endl;
}

Cvitancia::Cvitancia(const Cvitancia &t)
{
	number = t.number;
	date = t.date;
	cost = t.cost;
	cout << "Конструктор копирования для объекта:" << this << endl;
}

Cvitancia::~Cvitancia()
{
	cout << "Деструктор для объекта:" << this << endl;
}

int Cvitancia::get_number()
{
	return number;
}
string Cvitancia::get_date()
{
	return date;
}
double Cvitancia::get_cost()
{
	return cost;
}
void Cvitancia::set_number(int n)
{
	number = n;
}
void Cvitancia::set_date(string d)
{
	date = d;
}
void Cvitancia::set_cost(double c)
{
	cost = c;
}

void Cvitancia::show()
{
	cout << "number:" << number << endl;
	cout << "date:" << date << endl;
	cout << "cost:" << cost << endl;
}