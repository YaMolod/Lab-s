#include "List.h"
#include <iostream>
using namespace std;

List::List(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}
List::List(const List& l)
{
	size = l.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = l.data[i];
	}
	beg = l.beg;
	end = l.end;
}
List::~List()
{
	delete[]data;
	data = nullptr;
}
List& List::operator=(const List& l)
{
	if (this == &l) { return *this; }
	size = l.size;
	if (data != nullptr) { delete[]data; }
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = l.data[i];
	}
	beg = l.beg;
	end = l.end;
	return *this;
}
int& List::operator[](int index)
{
	if (index < size) { return data[index]; }
	else { cout << "Error: index > size" << endl; }
}
List List::operator+(const int k)
{
	List temp(size);
	for (int i = 0; i < size; i++)
	{
		temp.data[i] += data[i] + k;
	}
	return temp;
}

ostream& operator<<(ostream& out, const List& l)
{
	for (int i = 0; i < l.size; ++i)
	{
		out << l.data[i] << " ";
	}
	return out;
}
istream& operator>>(istream& in, List& l)
{
	for (int i = 0; i < l.size; ++i)
	{
		in >> l.data[i];
	}
	return in;
}

int List::operator()()
{
	return size;
}

