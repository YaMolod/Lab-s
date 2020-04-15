// Муллов Игорь, 14.2 (8э)  очередь через структуры (через структуры, 1-2 столбцы)

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Queue
{
    Queue* next;
    char* data;
};

Queue* make_queue(Queue*& first,Queue*& last, char* data, int n)
{
    first = new Queue;
    first->data = data;
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        Queue* p = new Queue;
        p->data = data;
        p->next = last;
        last = p;       
    }
    return last;
}

void Print(Queue* last)
{
    Queue* p = last;
    while (p)
    {
        cout << p->data << '\t';
        p = p->next;
    }
    cout << endl;
}

Queue* push(Queue*&first, Queue*& last, int k,int& n)
{
    Queue* p = last;
    Queue* r = new Queue;
    cout << "Введите элемент очереди:";
    char s[50];
    cin >> s;
    char* data = new char[strlen(s) + 1];
    strcpy(data, s);
    r->data = data;
    n++;
    if (k == 1)
    {
        r->next = NULL;
        first->next = r;
        return first;
    }
    else if (k==n)
    {
        r->next = last;
        last = r;
        return last;
    }
    for (int i = 1; i < n-k  && p->next != NULL; i++)
    {      
        p = p->next;
    }
    if (p != NULL)
    {
        r->next = p->next;
        p->next = r;
        return last;
    }    
}

Queue* clear(Queue*& first, Queue*& last)
{  
    while (last)
    {
        Queue* p = last;
        last = last->next;
        delete p;
        p = last;
    }
    last = NULL;
    first = NULL;
    return last;   
}

int main()
{
    setlocale(LC_ALL, "ru");
    Queue* first = NULL; Queue* last=NULL;
    int n=4; int k;
    cout << "Введеите количество элементов очереди:";
    cin >> n;
    char s[50];
    cout << "Введите элемент очереди:";
    cin >> s;
    char* data = new char[strlen(s) + 1];
    strcpy(data, s);
    make_queue(first, last, data, n);
    Print(last);  
    cout << "Введите номер элемента:";
    cin >> k;
    push(first, last, k,n);
    Print(last);
    clear(first, last);
    delete[]data;
}

