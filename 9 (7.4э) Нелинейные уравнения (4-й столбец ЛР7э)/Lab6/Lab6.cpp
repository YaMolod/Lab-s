//Муллов Игорь, 9 (7.4э) Нелинейные уравнения (4-й столбец ЛР7э)
#include <iostream>
#include <cmath>
using namespace std;

double func1(double x)
{
	return (3 * x - 4 * log(x) - 5);
}
double root1(double x, double e)
{
	double f, df;
	cout << "x0 = " << x;
	do {
		f = func1(x);
		df = 3 - (4 / x);
		x = x - f / df;
	} while (fabs(f) > e);
	return x;
}
void Newton() {
	setlocale(LC_ALL, "ru");
	cout << "\nКорень выражения (3 * x - 4 * log(x) - 5): " << root1(3, 0.000001) << endl;
	
}


double func2(double x)
{
	return (3 * x - 4 * log(x) - 5);
}
double root2(double x0, double x1, double e)
{

	double left = x0, right = x1, x, f;
	cout << "x0=" << x0 << "\nx1=" << x1;
	do {
		x = (left + right) / 2;
		f = func2(x);
		if (f > 0) right = x;
		else left = x;
	} while (fabs(f) > e);
	return x;
}
void division() {
	setlocale(LC_ALL, "ru");
	cout << "\nКорень выражения (3 * x - 4 * log(x) - 5): " << root2(2, 4, 0.000001) << endl;
	
}

double func3(double x)
{
	return (4 * log(x) + 5) / 3;
}
double root3(double x, double e)
{
	cout << "x0 = " << x;
	double x1 = x;
	do {
		x = x1;
		x1 = func3(x);
	} while (fabs(x - x1) > e);
	return x;
}
void iteration() {
	setlocale(LC_ALL, "ru");
	cout << "\nКорень уравнения (3 * x - 4 * log(x) - 5): " << root3(3, 0.000001) << endl;
	
}
int main()
{
	setlocale(LC_ALL, "ru");
	int num;
	do
	{
		cout << "1.Метод Ньютона\n2.Метод половинного деления\n3.Метод иттерации\n4.Выход\n";
		cout << "Выберите метод решения: ";
		cin >> num;
		switch (num)
		{
		case 1:
			Newton();
			
			break;
		case 2:
			division();
			
			break;
		case 3:
			iteration();
			
			break;
		case 4:
			return 0;
		default:
			cout << "Операция не выбрана. Выберите операцию\n";
			break;
		}
	} while (num != 4);
	return num;
}