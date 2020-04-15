//Муллов Игорь, 8 (8з) Структуры данных

#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>
using namespace std;

struct MUSICDISK
{
    MUSICDISK* next;
    char name[40];
    char author[40];
    float duration;
    float cost;
};

MUSICDISK* create_obj()
{
    MUSICDISK* p = new MUSICDISK;
    cout << "Введите название:";
    cin >> p->name;
    cout << "Введите автора:";
    cin >> p->author;
    cout << "Введите продолжительность:";
    cin >> p->duration;
    cout << "Введите стоимость:";
    cin >> p->cost;
    cout << endl;
    p->next = NULL;
    return p;
}

MUSICDISK* create_list(MUSICDISK*& first, int n)
{
    MUSICDISK* p = first;
    MUSICDISK* r;
    for (int i = 1; i < n; i++)
    {
        r = create_obj();
        p->next = r;
        p = r;
    }
    return first;
}

void print_list(MUSICDISK* first)
{
    MUSICDISK* p = first;
    while (p)
    {
        cout << "Автор:" << p->author << '\t';
        cout << "Название:" << p->name << '\t';
        cout << "Продолжительность:" << p->duration << '\t';
        cout << "Цена:" << p->cost << endl;
        p = p->next;
    }   
}

MUSICDISK* delete_obj(MUSICDISK*& first, float k,int n)
{
    MUSICDISK* p = first;
    MUSICDISK* ptr = nullptr;
    if (first->duration == k)
    {
        first = first->next;
        delete p;
        return first;
    }
    else {
        for (int i = 0; i < n - 1 && p->next != NULL; i++)
        {
            if (p->next->duration == k)
            {
                ptr = p->next;
                p->next = ptr->next;
                delete ptr;
                return first;
            }
            p = p->next;
            if (p->next == NULL)
            {
                return first;
            }
        }
    }
   
}

MUSICDISK* add_obj(MUSICDISK*& first,int num)
{
    MUSICDISK* p = first;
    for (int i = 0; i < num-1 && p->next != NULL; i++)
    {       
        p = p->next;
    }
    if (p != NULL)
    {
        for (int i = 0; i < 2; i++)
        {
            MUSICDISK* r = create_obj();
            r->next = p->next;
            p->next = r;
        }
        return first;
    }
}



int main()
{
    /*MUSICDISK* first = create_obj();
    create_list(first, n);
    print_list(first);  
    delete_obj(first, k, n);
    print_list(first);
    cin >> num;
    add_obj(first, num);
    print_list(first);*/
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
        
    string path = "newFile.txt";
    ofstream fout;
    fout.open(path);
    if (!fout.is_open())
    {
        cout << "Ошибка открытия!";
    }
    else
    {
        int num, n;
        float k;
        cout << "Введите количество композиций:";
        cin >> n;
        cout << endl;
        MUSICDISK* first = create_obj();        
        create_list(first, n);
        MUSICDISK* p = first;
        while (p)
        {
            fout << "Автор:" << p->author << '\t';
            fout << "Название:" << p->name << '\t';
            fout << "Продолжительность:" << first->duration << '\t';
            fout << "Цена:" << p->cost << endl;
            p = p->next;
        }
        p=first;
        fout <<endl;
        cout << "Укажите продолжительность:";
        cin >> k;
        delete_obj(first, k, n);
        p = first;
        while (p)
        {
            fout << "Автор:" << p->author << '\t';
            fout << "Название:" << p->name << '\t';
            fout << "Продолжительность:" << first->duration << '\t';
            fout << "Цена:" << p->cost << endl;
            p = p->next;
        }
        p = first;
        fout <<endl;
        cout << "Укажите номер элемента:";
        cin >> num;
        cout << endl;
        add_obj(first, num);        
        while (p)
        {
            fout << "Автор:" << p->author << '\t';
            fout << "Название:" << p->name << '\t';
            fout << "Продолжительность:" << first->duration << '\t';
            fout << "Цена:" << p->cost << endl;
            p = p->next;
        }      
       
    }
    fout.close();

    ifstream fin;
    fin.open(path);

    if (!fin.is_open())
    {
        cout << "Ошибка открытия!";
    }
    else
    {
        char ch;
        while (fin.get(ch))
        {
            cout<<ch;
        }
        
    }
    fin.close();

    return 0;
}

