//Муллов Игорь,14.1 (8э)  двунаправленные списки(через структуры, 1 - 2 столбцы)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
using namespace std;

struct Node
{
    char* data;
    Node* next;
    Node* prev;
};

Node* make_list(Node*& first, int n)
{
    Node* p; Node* r;
    p = new Node;
    char s[50];
    cout << "Введите элемент узла:" << endl;
    cin >> s;
    p->data = new char[strlen(s) + 1];
    strcpy(p->data, s);
    p->next = NULL;
    p->prev = NULL;
    first = p;
    for (int i = 1; i < n; i++)
    {
        r = new Node;
        r->prev = p;
        r->next = NULL;
        char s[50];
        cout << "Введите элемент узла:" << endl;
        cin >> s;
        r->data = new char[strlen(s) + 1];
        strcpy(r->data, s);
        p->next = r;
        p = r;
    }
    return first;
}

void Print(Node* first)
{
    cout << "Вывод списка:"<<endl;
    while (first)
    {
        cout << first->data<<'\t';
        first = first->next;
    }
}

Node* add(Node*& first,int k)
{
    Node* p = first;
    Node* r = new Node;
    r->prev = NULL;
    r->next = NULL;
    char s[50];
    cout << "Введите элемент узла:" << endl;
    cin >> s;
    r->data = new char[strlen(s) + 1];
    strcpy(r->data, s);
    if (k == 1)
    {
        r->next = first;
        first->prev = r;
        first = r;
        r->prev = NULL;
        return first;
    }
    for (int i = 1; i < k-1 && p->next != NULL; i++)
    {
        p = p->next;
    }
    if (p != NULL)
    {
        r->next = p->next;
        p->next = r;
        r->prev = p;        
        return first;
    } 
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* first = NULL;
    cout << "Введите количество узлов списка:";
    int n;
    cin >> n;
    int k;
    make_list(first, n);
    Print(first);
    cout << endl << "Введите номер элемента:";
    cin >> k;
    add(first, k);
    Print(first);
}

