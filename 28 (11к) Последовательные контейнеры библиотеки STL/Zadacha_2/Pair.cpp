#include "Pair.h"
#include <iostream>
using namespace std;

Pair& Pair::operator=(const Pair& t)
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	return *this;
}


istream& operator>>(istream& in, Pair& t)
{
	cout << "first:"; cin >> t.first;
	cout << "second:"; cin >> t.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& t)
{
	return(out << t.first << " : " << t.second << endl);
}

Pair& Pair::operator-(int s)
{
	this->first = this->first - s;
	this->second = this->second - s;
	return *this;
}

int& Pair::operator/(int s)
{
	int n = this->first + this->second;
	n = n / s;
	return n;
}

Pair& Pair::operator+(Pair& p)
{
	this->first += p.first;
	this->second += p.second;
	return *this;
}

bool Pair::operator>(const Pair& p)
{
	if (this->first + this->second > p.first + p.second) return true;
	return false;
}

bool Pair::operator<(const Pair& p)
{
	if (this->first + this->second < p.first + p.second) return true;
	return false;
}