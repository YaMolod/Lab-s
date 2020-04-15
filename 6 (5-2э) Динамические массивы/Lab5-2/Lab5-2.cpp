// Муллов Игорь, 6 (5-2э) Динамические массивы

#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int** A;
int m, n, k;

int** CreateArray (int rows, int cols)
{
	int** A = new int* [rows];
	for (int i = 0; i < rows; i++)
	{
		A[i] = new int[cols];
	}
	return A;
}

void FillArray(int** pA, int m, int n)
{
	/*for (int i = 0; i < m; i++)
	{
		pA[i] = new int[n];
	}*/
	
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			pA[i][j] = rand() % 101 - 50;			
		}		
	}
}

void PrintArray(int** pA, int m, int n)
{
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << pA[i][j] << '\t';
		}
		cout << endl;
	}
	cout << endl;
}

void push_back(int**& pA, int m, int &n,int k)
{
	n--;
	int** newpA = new int* [m];
	for (int i = 0; i < m; i++)
	{
		newpA[i] = new int[n];
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j <=k; j++)
		{
			newpA[i][j] = pA[i][j];
		}
		for (int j = k-1; j < n; j++)
		{
			newpA[i][j] = pA[i][j + 1];
		}	
	}
	
	for (int i = 0; i < m; i++)
	{
		delete[] pA[i];
	}
	delete[]pA;
	pA = newpA;
}


int main()
{
	srand(time(NULL));
	setlocale(LC_ALL, "ru");
	int selection = 0;
	
	do
	{
		cout << "Выберите действие" << endl <<
			"1.Формирование массива" << endl <<
			"2.Печать массива" << endl <<
			"3.Удаление столбца массива" << endl <<
			"4.Выход" << endl;

		cin >> selection;
		switch (selection)
		{
		case 1:
			cout << "Введите количество строк массива:";
			cin >> m;
			cout << "Введите количество столбцов массива:";
			cin >> n;
			A = CreateArray(m, n);
			FillArray(A, m, n);
			break;
		case 2:

			PrintArray(A, m, n);
			break;
		case 3:

			cout << "Введите номер столбца:";
			cin >> k;
			while (k<1 || k>n)
			{
				cout << "Ошибка! Ведите другой номер" << endl;
				cin >> k;
			}
			push_back(A, m, n, k);
			break;
		case 4:
			cout << "Выход из меню" << endl;
			break;
		default:
			cout << "Пункт в меню отсутствует" << endl;
			break;
		}

	} while (selection != 4);
	return selection;
	


	for (int i = 0; i < m; i++)
	{
		delete [] A[i];
	}
	delete[] A;		
}
