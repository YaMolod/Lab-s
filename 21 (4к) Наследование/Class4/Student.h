#pragma once
#include "Person.h"
#include <string>
using namespace std;

class Student : public Person	
{
public:
	Student(void);
	~Student(void);
	Student(string, int, int);
	Student(const Student&);
	int get_year() { return year; }
	void set_year(int);
	void increase_year(int);
	Student& operator=(const Student&);
	friend istream& operator>>(istream& in, Student& p);
	friend ostream& operator<<(ostream& out, const Student& p);
protected:
	int year;
};

