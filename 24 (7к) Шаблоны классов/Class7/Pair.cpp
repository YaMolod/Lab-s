#include "Pair.h"

Pair::Pair(void)
{
	first = second = 0;
}
Pair::Pair(int f, double s)
{
	first = f;
	second = s;
}
Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}
Pair& Pair::operator=(const Pair& p)
{
	first = p.first;
	second = p.second;
	return *this;
}
ostream& operator<<(ostream& out, const Pair& p)
{
	out << p.first << " : " << p.second << endl;
	return out;
}
istream& operator>>(istream& in, Pair& p)
{
	cout << "first:"; in >> p.first;
	cout << "second:"; in >> p.second;
	return in;
}
Pair Pair::operator+(int k)
{
	this->first += k;
	this->second += k;
	return *this;
}