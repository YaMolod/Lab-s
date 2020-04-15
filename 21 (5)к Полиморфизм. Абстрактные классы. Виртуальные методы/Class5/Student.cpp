#include "Student.h"

Student::Student(void) : Person()
{
	year = 0;
}
Student::~Student(void)
{

};
Student::Student(string n, int a, int y) : Person(n, a)
{
	year = y;
}
Student::Student(const Student& s)
{
	name = s.name;
	age = s.age;
	year = s.year;
}
void Student::set_year(int y)
{
	year = y;
}
void Student::increase_year(int y)
{
	year += y;
}
Student& Student::operator=(const Student& s)
{
	if (&s == this) { return *this; }
	name = s.name;
	age = s.age;
	year = s.year;
	return*this;
}
istream& operator>>(istream& in, Student& s)
{
	cout << "name:"; in >> s.name;
	cout << "age:"; in >> s.age;
	cout << "year:"; in >> s.year;
	return in;
}
ostream& operator<<(ostream& out, const Student& s)
{
	out << "name:" << s.name << endl;
	out << "age:" << s.age << endl;
	out << "year:" << s.year << endl;
	return out;
}
void Student::Show()
{
	cout << "name:" << name << endl;
	cout << "age:" << age << endl;
	cout << "year:" << year << endl;
}