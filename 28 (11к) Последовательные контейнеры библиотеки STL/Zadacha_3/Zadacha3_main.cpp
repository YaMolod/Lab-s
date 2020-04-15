#include <C:\Users\skyst\source\repos\Class11\Zadacha_2\Pair.h>
#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int n,pos,a,b,key;
	cout << "Количество элементов списка:";
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
	cout << "Диапозон от:"; cin >> a; cout << "до:"; cin >> b;
	cout << "Значение first из диапозона:"; cin >> key;
	lis.Del(n, a, b, key);
	lis.Print();
}