#pragma once
#include <iostream>
#include <list>
using namespace std;

template <class T>
class List
{
public:
	List(void);
	List(int n);
	void Print();
	~List();
	T srednee();
	void Add(T e1, int pos);
	void vichest(T e1);
	void Del(int& n, int a, int b, int key);
private:
	int size;
	list <T> l;
};

template <class T>
List<T>::List()
{
	size = 0;
}
template<class T>
List<T>::~List(void)
{

}
template<class T>
List<T>::List(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		l.push_back(a);
	}
	size = l.size();
}

template<class T>
void List<T>::Print()
{
	for (auto i = l.begin(); i != l.end(); ++i) cout << *i;
	cout << endl;
}

template<class T>
T List<T>::srednee()
{
	T temp;
	for (auto i = l.begin(); i != l.end(); ++i) temp = temp + *i;
	int n = l.size();
	T p(temp/n, temp/n);
	return p;
}

template<class T>
void List<T>::Add(T e1, int pos)
{
	auto i = l.begin();
	advance(i, pos - 1);
	l.insert(i, e1);
}

template<class T>
void List<T>::vichest(T p)
{
	int sum = p.get_first();
	for (auto i = l.begin(); i != l.end(); ++i) *i = *i - sum;
}

template<class T>
void List<T>::Del(int& n, int a, int b, int key)
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
}

