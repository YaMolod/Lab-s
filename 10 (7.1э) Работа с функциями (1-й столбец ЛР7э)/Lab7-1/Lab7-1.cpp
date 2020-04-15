// Муллов Игорь, 10 (7.1э) Работа с функциями (1й столбец ЛР7э)

#include <iostream>
#include <stdlib.h>
#include <windows.h>
using namespace std;

void Printf(const char name[]="Игорь",const char surname[]="Муллов",const char middlename[]="Евгеньевич")
{
    cout << surname <<'\t';
    cout << name <<'\t';
    cout << middlename << '\t' << endl;;
}

int main()
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    const int n = 20;
    char Name[n];
    char Surname[n];
    char Middlename[n];
    cout << "Введите имя:" << endl;
    cin.getline(Name,20);
    cout << "Введите фамилию:" << endl;
    cin.getline(Surname, 20);
    cout << "Введите отчество:" << endl;
    cin.getline(Middlename, 20);
    cout << endl;
   
    Printf();
    Printf(Name);
    Printf(Name, Surname);
    Printf(Name, Surname, Middlename);
           
}

