﻿//Муллов Игорь, 16 (9э) Методы поиска Бойера-Мура и интерполяции
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <ctime>
using namespace std;

char txt[] = "Мы любим лабораторные работы";
const char pat[] = "лаб";
int* A;

void inter(int key,int *A,int n)
{
	int left = 0;
	int right = n - 1;	
	bool flag;
	for ( flag = false; (A[left] < key) && (A[right] > key) && !flag; )
	{
		
		int mid = left + ((key - A[left]) * (right - left)) / (A[right] - A[left]);
		
		if (A[mid] < key)
			left = mid + 1;
		else if (A[mid] > key)
			right = mid - 1;
		else
			flag = true;
	}
	if (A[left] == key)
	{
		cout << key << " Найден в элементе " << left << endl;
	}		
	else if (A[right] == key)
	{
		cout << key << " Найден в элементе " << right << endl;
	}		
	else
	{
		cout << "Ключ не найден" << endl;
	}
		
}

int BMsearch(char* str, const char* word)
{
	int N = strlen(str);
	int M = strlen(word);

	int* d = new int[256];
	int i;
	for (i = 0; i < 256; i++)
		d[i] = M;

	for (i = 0; i < M - 1; i++)
		d[(unsigned char)word[i]] = M - i - 1;

	int result;
	for (i = M; i <= N; i += d[(unsigned char)str[i - 1]])
	{
		int j, k;
		for (j = M - 1, k = i - 1; j >= 0 && str[k] == word[j]; k--, j--);
		if (j < 0)
		{
			result = i - M;
			break;
		}
		if (i == N)
		{
			result = -1;
			break;
		}
	}
	delete d;
	return result;
}

int main()
{
	setlocale(LC_ALL, "ru");
	srand(time(NULL));
	int selection = 0;
	do
	{
		cout << "1.Поиск методом интерполяции" << endl
			<< "2.Поиск алгоритмом Бойера-Мура" << endl
			<< "3.Выход" << endl;		
		cin >> selection;
		switch (selection)
		{
		case 1:
			int n, key;
			cout << "Введите длину массива:";
			cin >> n;
			 A = new int[n];
			for (int i = 0; i < n; i++)
			{
				A[i] = rand() % 200 - 100;
			}
			for (int i = 0; i < n; i++)
			{
				for (int j = n - 1; j >= i; j--)
				{
					while (A[j] < A[j - 1])
					{

						int tmp = A[j];
						A[j] = A[j - 1];
						A[j - 1] = tmp;
					}
				}
			}
			for (int i = 0; i < n; i++)
			{
				cout << A[i] << " ";
			}
			cout << endl;
			cout << "Введите ключ:";
			cin >> key;
			inter(key, A, n);
			break;
		case 2:
			cout << "Текст:" << txt << '\t' << "Подстрока:" << pat << endl << endl;
			
			cout << "Подстрока найдена на сдвиге:" << BMsearch(txt, pat) << endl << endl;
			break;
		case 3:
			break;
		default:
			cout << "Error";
		}
	} while (selection != 3);
	return selection;
	
}