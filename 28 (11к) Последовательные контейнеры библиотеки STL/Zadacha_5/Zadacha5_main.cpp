#include <C:\Users\skyst\source\repos\Class11\Zadacha_2\Pair.h>
#include <iostream>
#include <list>
#include "List.h"
#include <queue>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n, pos, a, b, key;
	cout << "���������� ��������� ������:";
	cin >> n;
	List<Pair>l(n);
	l.Print();
	cout << "������� ������:";
	cin >> pos;
	Pair p = l.srednee(n);
	l.Add(p, pos, n);
	l.Print();
	p = l.srednee(n);
	l.vichest(p);
	l.Print();
	cout << "�������� ��:"; cin >> a; cout << "��:"; cin >> b;
	cout << "�������� first �� ���������:"; cin >> key;
	l.Del( n, a, b, key);
	l.Print();
} 