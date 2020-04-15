//Муллов Игорь,28 (11к) Последовательные контейнеры библиотеки STL
#include <iostream>
#include <list>
#include <cstdlib>
using namespace std;

typedef list<int>List;

List make_list(int n)
{
	List l;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100 - 50;
		l.push_back(a);
	}
	return l;
}

void print_list(const List& l)
{
	for (auto i = l.begin(); i != l.end(); ++i) cout << *i << " ";
	cout << endl;	
}

List sred_ar(List& l,int& n)
{
	int sum = 0, pos;
	for (auto i = l.begin(); i != l.end(); ++i) sum+=*i;
	sum = sum / n;
	cout << "Позиция списка:"; cin >> pos;
	auto i = l.begin();
	advance(i, pos-1);
	l.insert(i, sum);
	n++;
	return l;
}

List vichest(List& l,int n)
{
	int sum = 0, pos;
	for (auto i = l.begin(); i != l.end(); ++i) sum += *i;
	sum = sum / n;
	for (auto i = l.begin(); i != l.end(); ++i) *i=*i - sum;
	return l;
}


List del(List& l, int& n,int a,int b,int key)
{
	auto i = l.begin();
	auto j = l.begin();
	advance(i, a);
	advance(j, b);
	int pos=-1;
	for (i; i != j; ++i)
	{
		if (*i == key)
		{
			pos = *i;
		}
	}
	if (pos != -1)
	{
		l.remove(pos);
		n--;
	}	
	return l;
}

int main()
{
	setlocale(LC_ALL, "ru");
	try
	{
		List l;
		int n, a, b, key;
		cout << "Количество элементов списка:"; cin >> n;
		l = make_list(n);
		print_list(l);
		sred_ar(l, n);
		print_list(l);
		cout << "Диапозон от:"; cin >> a; cout << "до:"; cin >> b;
		cout << "Значение из диапозона:"; cin >> key;
		del(l, n, a, b, key);
		print_list(l);
		cout << "Вычитание" << endl;
		vichest(l, n);
		print_list(l);
	}
	catch (int)
	{
		cout << "Error";
	}
}