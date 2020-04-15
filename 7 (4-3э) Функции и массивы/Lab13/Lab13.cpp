// Муллов Игорь, 7 (4-3э) Функции и массивы

#include <iostream>
#include <string>
#include <Windows.h>
using namespace std;

void sortstr(string& str)
{	
	int lenstr = str.length(), wcnt = 0, j = 0;
	if (lenstr > 0)
	{
		
		if (lenstr == 1 && str[0] != ' ')
			wcnt = 1;
		else
		{
			for (int i = 0; i < lenstr - 1; i++)
			{
				if ((str[i] == ' ' && str[i + 1] != ' ') || (i == 0 && str[i] != ' '))
					wcnt++;
			}
		}
				
		string* warr = new string[wcnt];
		
		for (int i = 0; i < lenstr; i++)
		{
			
			while (str[i] != ' ' && i < lenstr)
			{
				warr[j] += str[i];
				i++;
			}
			
			j++;

		}
		
		for (int i = 0; i < wcnt - 1; i++)
		{
			for (int j = 0; j < wcnt - i - 1; j++)
			{
				if (warr[j][0] > warr[j + 1][0])
				{
					swap(warr[j], warr[j + 1]);
				}
			}
		}
		
		str = warr[0] + ' ';
		for (int i = 1; i < wcnt; i++)
		{
			str = str + warr[i] + ' ';
		}
		delete[] warr;
	}
}


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	string str;
	cout << "Введите строку:" << endl;
	getline(cin, str);
	sortstr(str);
	cout << "Отсортированная строка: "<<endl << str;
}

