//Муллов Игорь, 15 Сортировка стека через stl-контейнеры
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    setlocale(LC_ALL, "ru");

    stack<int> first;
    stack<int> second;
    stack<int> third;


    int k;
    int n;
    cout << "Введите длину стека:";
    cin >> n;
    cout << "Изначальный стек:";
    for (int i = 0; i < n; i++)
    {
        first.push(k = rand() % 100 - 50);
        cout << k << " ";
    }
    cout << endl;
    int min, tmp;
    while (!first.empty())
    {
        min = first.top();
        first.pop();
        second.push(min);
        while (!first.empty())
        {
            tmp = first.top();
            first.pop();
            if (tmp > min)
            {
                min = tmp;
            }
            second.push(tmp);
        }
        while (!second.empty())
        {
            tmp = second.top();
            second.pop();
            if (tmp == min)
            {
                third.push(tmp);
            }
            else first.push(tmp);
        }
    }
    cout << "Стек после сортировки: ";
    while (!third.empty())
    {
        cout << third.top() << " ";
        third.pop();
    }

    return 0;
}