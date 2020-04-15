//Муллов Игорь, 17 (9э) Методы сортировки массивов данных подсчётом и быстрая

#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
int first, last;
int* A;
int* c;
int n, selection;
int k;

void fill_array(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100 - 50;
    }
}

void print_array(int* arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl << endl;
}

void quicksort(int* arr, int first, int last)
{
    int pivot, tmp;
    int l = first, r = last;
    pivot = arr[(l + r) / 2];
    do
    {
        while (arr[l] < pivot) l++;
        while (arr[r] > pivot) r--;
        if (l <= r)
        {

            tmp = arr[l];
            arr[l] = arr[r];
            arr[r] = tmp;
            l++;
            r--;
        }
    } while (l < r);

    if (first < r)
    {
        quicksort(arr, first, r);
    }
    if (l < last)
    {
        quicksort(arr, l, last);
    }
}

void CountingSort(int* A, int* c, int n, int k)
{
    for (int i = 0; i < k; i++)
    {
        c[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        c[A[i]] = c[A[i]] + 1;
    }
    int i = 0;
    for (int j = 0; j < k; j++)
    {
        while (c[j] != 0)
        {
            A[i] = j;
            c[j]--;
            i++;
        }
    }
}

int main()
{
    srand(time(NULL));
    setlocale(LC_ALL, "ru");

    do
    {
        cout << "1.Быстрая сортировка" << endl
            << "2.Сортировка подсчетом" << endl
            << "3.Выход" << endl;
        cin >> selection;
        switch (selection)
        {
        case 1:
            cout << "Введите длину массива:";
            cin >> n;
            A = new int[n];
            first = 0; last = n - 1;
            fill_array(A, n);
            cout << "Изначальный массив:" << endl;
            print_array(A, n);
            quicksort(A, first, last);
            cout << "Массив после сортировки:" << endl;
            print_array(A, n);
            delete[]A;
            break;

        case 2:
            cout << "Введите длину массива:";
            cin >> n;
            A = new int[n];
            cout << "Диапозон чисел массива от 0 до k. Введите k:";
            cin >> k;
            c = new int[k];
            for (int i = 0; i < n; i++)
            {
                A[i] = rand() % k;
            }
            cout << "Изначальный массив:" << endl;
            print_array(A, n);
            CountingSort(A, c, n, k);
            cout << "Массив после сортировки:" << endl;
            print_array(A, n);
            delete[]A;
            break;

        case 3:
            break;
        default:
            cout << "Error";
            break;
        }
    } while (selection != 3);
    return selection;
}

