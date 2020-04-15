//Муллов Игорь, 11 Методы сортировки массивов вставки, обмена и выбора
#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

int n, min, tmp;

int* A = new int[n];

void FillArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		arr[i] = rand() % 100 - 50;
	}
}

void PrintArray(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void Vstavka(int* arr, int n)
{
	for (int i = 1; i < n; i++)
	{
		int tmp = arr[i];
		int j = i - 1;
		while (j >= 0 && tmp < arr[j])
		{
			cout << "Сравниваются:" << "  " << arr[j] << " " << tmp << endl;
			arr[j + 1] = arr[j];
			j--;

		}
		arr[j + 1] = tmp;

	}
}

void Puzirek(int* arr, int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = n - 1; j >= i; j--)
		{
			while (arr[j] < arr[j - 1])
			{
				cout << "Сравниваются:" << "  " << arr[j] << " " << arr[j - 1] << endl;
				int tmp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = tmp;
			}
		}
	}
}

void Vibor(int* arr, int n)
{
	for (int i = 0; i < n - 1; i++)
	{
		int min = i;
		for (int j = i + 1; j < n; j++)
		{
			if (arr[j] < arr[min])
			{
				cout << "Сравниваются:" << "  " << arr[j] << " " << arr[min] << endl;
				int tmp = arr[j];
				min = j;
			}
			int tmp = arr[i];
			arr[i] = arr[min];
			arr[min] = tmp;
		}
	}
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int selection = 0;

	do
	{
		cout << "1.Метод вставки" << endl <<
			"2.Метод пузырька" << endl <<
			"3.Метод выбора" << endl <<
			"4.Выход" << endl;
		cin >> selection;
		switch (selection)
		{
		case 1:
			cout << "Введите длину массива:";
			cin >> n;
			FillArray(A, n);
			PrintArray(A, n);
			Vstavka(A, n);
			PrintArray(A, n);
			break;

		case 2:
			cout << "Введите длину массива:";
			cin >> n;
			FillArray(A, n);
			PrintArray(A, n);
			Puzirek(A, n);
			PrintArray(A, n);
			break;
		case 3:
			cout << "Введите длину массива:";
			cin >> n;
			FillArray(A, n);
			PrintArray(A, n);
			Vibor(A, n);
			PrintArray(A, n);
			break;
		case 4:
			break;
		default:
			cout << "Error"<<endl;
			break;
		}
	} while (selection != 4);
	return selection;
	delete[] A;
}