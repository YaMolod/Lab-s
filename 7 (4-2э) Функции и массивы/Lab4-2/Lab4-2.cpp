// Муллов Игорь, 7 (4-2э) Функции и массивы
//

#include <iostream>
#include <stdlib.h>
using namespace std;

void FillArray (int (&arr)[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr[i][j] = rand() % 100 - 50;
        }
    }
}

void PrintArray (int(&arr)[100][100], int m, int n)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << '\t';
        }
        cout << endl;
    }
    cout << endl;
}

void TranspArray(int(&arr)[100][100], int m, int n)
{
    int tmp;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j % 2 == 0)
            {
                tmp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = tmp;
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "ru");
    int m, n;
    cout << "Введите количество строк" << endl;
    cin >> m;
    cout << "Введите количество столбцов" << endl;
    cin >> n;
    int A[100][100];

    FillArray(A, m, n);
    PrintArray(A, m, n);

    TranspArray(A, m, n);
    PrintArray(A, m, n);
}

