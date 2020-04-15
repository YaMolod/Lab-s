//Муллов Игорь, 20 (1к) Классы и объекты. Инкапсуляция
#include <iostream>
using namespace std;

fraction make_fraction(int F, double S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

void main()
{
	fraction A;
	fraction B;
	A.Init(5, 1.5);
	B.Read();
	A.Show();
	B.Show();

	cout << "A.Cost:" << A.Cost() << endl;
	cout << "B.Cost:" << B.Cost() << endl;

	fraction* x = new fraction;
	x->Init(4, 1.7);
	x->Show();
	x->Cost();
	cout << "x.Cost:" << x->Cost() << endl;

	fraction mas[3];
	for (int i = 0; i < 3; i++)
	{
		mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		mas[i].Cost();
		cout << "mas[i].Cost():" << mas[i].Cost() << endl;
	}

	fraction* p_mas = new fraction[3];
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		p_mas[i].Cost();
		cout << "p_mas[i].Cost():" << p_mas[i].Cost() << endl;
	}

	int y; double z;
	cout << "first:"; cin >> y;
	cout << "second:"; cin >> z;

	fraction F = make_fraction(y, z);
	F.Show();
	
}