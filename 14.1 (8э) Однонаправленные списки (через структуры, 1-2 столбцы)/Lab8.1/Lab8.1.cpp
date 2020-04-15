//Муллов Игорь, 14.1 (8э) Однонаправленные списки (через структуры, 1-2 столбцы)
#include <iostream>
#include <stdlib.h> 
#include <ctime>

using namespace std;


struct Node
{
    int data;
    Node* next;
};

Node* make_list(Node*& first, int n)
{
    Node* p; Node* r;
    p = new Node;
    p->data = rand() % 100 - 50;
    p->next = NULL;
    first = p;
    for (int i = 1; i < n; i++)
    {
        r = new Node;
        r->data = rand() % 100 - 50;
        r->next = NULL;
        p->next = r;
        p = r;
    }
    return first;
}
void Print(Node* first)
{
    while (first)
    {
        cout << first->data << '\t';
        first = first->next;
    }
    cout << endl;
}

Node* del(Node*& first,int n)
{
    Node* tmp = nullptr;
    Node* ptr = nullptr;
    Node* p = first;
    for (int i = 1; i < n - 1 && p->next != NULL; i++)
    {        
        

        p = p->next;
       
       
        if (p->next->data % 2 == 0 && p->next != NULL)
        {
            ptr = p;
            tmp = p->next;
        }  
    }
    if (tmp == nullptr && first->data%2!=0)
    {
        return first;
    }  
    else if (tmp!=nullptr)
    {
        ptr->next = tmp->next;
        delete tmp;
        return first;
       
    }
    else 
    {       
        p = first;
        first = first->next;
        delete p;
    }  
    
}

Node* clear(Node* first)
{
    while (first)
    {
        Node* p = first;
        first = first->next;
        delete p;
    }
    first = NULL;
    return first;
}


int main()
{
    setlocale(LC_ALL, "ru");
    srand(time(NULL));
    Node* first = NULL;
    int n;
    cout << "Введите количество узлов:";
    cin >> n;
    int k = 0;
    make_list(first, n);
    Print(first);
    
    del(first,n);
   
    Print(first);
    clear(first);
}


