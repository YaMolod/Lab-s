// Муллов Игорь, 6 (5-1э) Динамические массивы

#include <iostream>
#include <stdlib.h>
using namespace std;

int* A;
int n;


int* CreateArray(int size)
{
    int* A = new int[size];
    return A;
}

void FillArray(int* pA, int n)
{
    for (int i = 0; i < n; i++)
    {
        pA[i] = rand() % 100;
    }
}

void PrintArray(int* pA, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << pA[i] << " ";
    }
    cout << endl;
}

void push_back(int*& pA, int& n, int tmp)
{
    int* newpA = new int[n + 1];
    for (int i = 0; i < n; i++)
    {
        newpA[i] = pA[i];
    }
    newpA[n] = tmp;
    n++;
    delete[]pA;
    pA = newpA;
}

int main()
{
    setlocale(LC_ALL, "rus");
    int tmp;
    
    int selection = 0;
    
    do
    { 
         cout << "Выберите действие" << endl <<
        "1.Формирование массива" << endl <<
        "2.Печать массива" << endl <<
        "3.Добавление элемента в массив" << endl <<
        "4.Выход" << endl;
         
        cin>>selection;
        switch (selection)
        {
        case 1:
            cout << "Введите длину массива:";
            cin >> n;  
            A = CreateArray(n);
            FillArray(A, n);            
            break;
        case 2:
            
            PrintArray(A, n);
            break;
        case 3:
            
            cout << "Введите элемент:";
            cin >> tmp;
            push_back(A, n, tmp);
            break;
        case 4:
            cout << "Выход из меню" << endl;
            break;
        default:
            cout << "Пункт в меню отсутствует" << endl;
            break;
        }

    }
    while (selection!= 4);
    return selection;

    delete[] A;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
