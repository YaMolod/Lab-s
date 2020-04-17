#include <iostream>
#include <string>
using namespace std;

class Cvitancia
{
	int number;
	string date;
	double cost;
public:
	Cvitancia();
	Cvitancia(int, string, double);
	Cvitancia(const Cvitancia&);
	~Cvitancia();
	int get_number();
	void set_number(int);
	string get_date();
	void set_date(string);
	double get_cost();
	void set_cost(double);
	void show();
};
