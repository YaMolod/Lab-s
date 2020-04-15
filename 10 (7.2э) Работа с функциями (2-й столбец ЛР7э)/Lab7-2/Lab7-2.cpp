// Муллов Игорь, 10 (7.2э) Работа с функциями (2-й столбец ЛР7э)

#include <iostream>
#include <stdlib.h>
using namespace std;

void Print(int n, int first, ...)
{    
    int* p = &first;
    while (n--)
    {
        cout << *p << " ";
        p++;
    }
    cout << endl;
}

void Max(int n,int first, ...)
{
    int max = 0;
    int* p = &first;
    while(n--)
    {
        if (max < *p)
        {
            max = *p;          
        }
        p++;
    }
    cout << max << endl;
}

int main()
{
    setlocale(LC_ALL, "ru");
    cout << "Маскимальный элемент: 22,33,44,55:" << endl;
    Max(4, 22, 33, 44, 55);
    cout << "Маскимальный элемент: 6,54,-6372,28,322,1,4309:" << endl;
    Max(6, 54, -6372, 28, 322, 1, 4309);    
}

