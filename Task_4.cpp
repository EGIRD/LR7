#include "Task_4.h"
#include <iostream>

int InputInt();
int Number_11(int);
int Number_31(int);
int Number_113(int);

void Task_4() {
    int a;
    std::cout << "Данная программа проверяет, делится ли введенное число на числа(11, 31, 113)\nВведите число: ";
    //std::cin >> a;
    a = InputInt();

    if(a < 0) a = -a;

    Number_11(a);
    Number_31(a);
    Number_113(a);
}

int Number_11(int a)
{
    while(true){
        if (a == 11)
        {std::cout << "Введенное вами число делится на 11\n"; break;}
        if (a < 11)
        {std::cout << "Введенное вами число не делится на 11\n"; break;}

        long long q = a >> 1;
        long long r = a & 1;
        a = q + 6 * r;
    }

    return a;
}

int Number_31(int a)
{
    while(true){
        (a < 0) ? -a : a;
        if (a == 31)
        {std::cout << "Введенное вами число делится на 31\n"; break;}
        if (a < 31)
        {std::cout << "Введенное вами число не делится на 31\n"; break;}

        long long q = a >> 1;
        long long r = a & 1;
        a = q + 16 * r;
    }

    return a;
}

int Number_113(int a)
{
    while(true){
        (a < 0) ? -a : a;
        if (a == 113)
        {std::cout << "Введенное вами число делится на 113\n"; break;}
        if (a < 113)
        {std::cout << "Введенное вами число не делится на 113\n"; break;}

        long long q = a >> 1;
        long long r = a & 1;
        a = q + 57 * r;
    }

    return a;
}
