#pragma once
#include <iostream>
#include <queue>
#include <list>
using namespace std;

template <class T>
class List
{
public:
	List(void);
	List(int n);
	void Print();
	List(const List<T>&);
	~List();
	T srednee(int n);
	void Add(T e1, int pos,int&n);
	void vichest(T e1);
	void Del(int& n, int a, int b, int key);
private:
	int size;
	queue <T> q;
};

template<class T>
list<T> copy_pq_to_list(queue<T> qp)
{
	list<T>lis;
	while (!qp.empty())
	{
		lis.push_back(qp.front());
		qp.pop();
	}
	return lis;
}

template<class T>
queue<T> copy_list_to_qp(list<T>lis)
{
	queue<T> qp;
	for (auto i = lis.begin(); i != lis.end(); ++i) qp.push(*i);
	return qp;
}

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
		q.push(a);
	}
	size = q.size();
}

template<class T>
List<T>::List(const List<T>& l)
{
	size = l.size;
	list lis = copy_pq_to_list(l.q);
	q = copy_list_to_pq(lis);
}

template<class T>
void List<T>::Print()
{
	list<T> lis = copy_pq_to_list(q);
	while (!q.empty())
	{
		cout << q.front();
		q.pop();
	}
	cout << endl;
	q = copy_list_to_qp(lis);
}

template<class T>
T List<T>::srednee(int n)
{
	list<T>lis = copy_pq_to_list(q);
	T sum;
	while (!q.empty())
	{
		sum = sum + q.front();
		q.pop();
	}
	q = copy_list_to_qp(lis);
	T p(sum / n, sum / n);
	return p;
}

template<class T>
void List<T>::Add(T e1, int pos,int& n)
{
	list<T>lis;
	T p;
	int i = 1;
	while (!q.empty())
	{
		p = q.front();
		if (i == pos)
		{
			lis.push_back(e1);
			n++;
		}
		lis.push_back(p);
		q.pop();
		i++;
	}
	q = copy_list_to_qp(lis);
}

template<class T>
void List<T>::vichest(T p)
{
	T temp;
	int sum = p.get_second();
	list<T>lis;
	while (!q.empty())
	{
		temp = q.front();
		lis.push_back(temp-sum);
		q.pop();
	}
	q = copy_list_to_qp(lis);
}

template<class T>
void List<T>::Del(int& n, int a, int b, int key)
{
	list<T>lis = copy_pq_to_list(q);
	auto i = lis.begin();
	auto j = lis.begin();
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
		lis.erase(i);
		n--;
	}
	q = copy_list_to_qp(lis);
}
