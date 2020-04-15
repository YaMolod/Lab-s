// Муллов Игорь, 14.2 (8э) Стек через структуры (через структуры, 1-2 столбцы)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node
{
    Node* next;
    char* data;
};

Node* create_stack(Node*& top, char* data,int n)
{
    Node* r; 
    for (int i = 1; i < n; i++)
    {
        r = new Node;
        r->data = data;
        r->next = top;
        top = r;
    }   
    return top;
}

void print(Node* top)
{
    Node* p = top;   
    while (p!=NULL)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

Node* push(Node*& top,int k)
{
    Node* p = top;
    Node* r = new Node;
    cout << "Введите элемент стека:";
    char s[50];
    cin >> s;
    char* data = new char[strlen(s) + 1];
    strcpy(data, s);
    r->data = data;
    if (k == 1)
    {
        r->next = top;
        top = r;
        return top;
    }
    for (int i = 1; i < k - 1 && p->next != NULL; i++)
    {
        p = p->next;
    }
    if (p!= NULL)
    {
        r->next = p->next;
        p->next = r;
    }
    return top;
}

Node* clear(Node*& top)
{
    while (top)
    {
        Node* p = top;
        top = top->next;
        delete p;
        p = top;
    }
    top = NULL;
    return top;
}

int main()
{    
    setlocale(LC_ALL, "ru");
    int n ; int k;
    cout << "Введеите количество элементов стека:";
    cin >> n;
    Node* top = new Node;
    char s[50];
    cout << "Введите элемент стека:";
    cin >> s;
    char* data = new char[strlen(s) + 1];
    strcpy(data, s);
    top->data = data;
    top->next = NULL;
    create_stack(top, data,n);
    print(top);
    cout << "Введите номер элемента:";
    cin >> k;
    push(top, k);
    print(top);
    clear(top);
    delete[]data;
}


