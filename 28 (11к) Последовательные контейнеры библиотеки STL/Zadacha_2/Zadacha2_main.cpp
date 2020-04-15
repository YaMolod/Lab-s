#include "Pair.h"
#include <iostream>
#include <list>
using namespace std;

typedef list<Pair>List;

List make_list(int n)
{
	Pair p;
	List l;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		l.push_back(p);
	}
	return l;
}

void print_list(const List& l)
{
	for (auto i = l.begin(); i != l.end(); ++i) cout << *i;
	cout << endl;
}

List sred_ar(List& l, int& n)
{
	Pair temp;
	int pos;
	for (auto i = l.begin(); i != l.end(); ++i) temp=temp + *i;
	cout << "Позиция списка:"; cin >> pos;
	auto i = l.begin();
	advance(i, pos - 1);
	int sum = temp / n;
	Pair p(sum, sum);
	l.insert(i, p);
	n++;
	return l;
}

List vichest(List& l, int n)
{
	Pair temp;
	for (auto i = l.begin(); i != l.end(); ++i) temp = temp + *i;
	int sum = temp / n;
	for (auto i = l.begin(); i != l.end(); ++i) *i = *i - sum;
	return l;
}

List del(List& l, int& n, int a, int b, int key)
{
	auto i = l.begin();
	auto j = l.begin();
	advance(i, a);
	advance(j, b);
	for (i; i != j; ++i)
	{
		if (i->get_first() == key)
		{
			break;
		}
	}	
	if (i != --j)
	{
		l.erase(i);
		n--;		
	}
	return l;
}


int main()
{
	setlocale(LC_ALL, "ru");
	List l;
	int n,a,b,key;
	cout << "Количество элементов списка:";
	cin >> n;
	l = make_list(n);
	print_list(l);
	sred_ar(l, n);
	print_list(l);
	vichest(l, n);
	print_list(l);
	cout << "Диапозон от:"; cin >> a; cout << "до:"; cin >> b;
	cout << "Значение first из диапозона:"; cin >> key;
	del(l, n, a, b, key);
	print_list(l);
}