#include <C:\Users\skyst\source\repos\Class11\Zadacha_2\Pair.h>
#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n,pos,a,b,key;
	cout << "���������� ��������� ������:";
	cin >> n;
	List<Pair>lis(n);
	lis.Print();
	Pair p = lis.srednee();
	cout << "pos:"; cin >> pos;
	lis.Add(p, pos);
	lis.Print();
	p = lis.srednee();
	lis.vichest(p);
	lis.Print();
	cout << "�������� ��:"; cin >> a; cout << "��:"; cin >> b;
	cout << "�������� first �� ���������:"; cin >> key;
	lis.Del(n, a, b, key);
	lis.Print();
}