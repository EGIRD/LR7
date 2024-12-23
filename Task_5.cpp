#include <iostream>
#include <cmath>
#include "Task_5.h"

char* statisticdayone(char* , char* );
char* statisticdaytwo(char* , char* );
int tehnsistem(char* , int );

void Task_5()
{
    std::cout << "Введите номер бочки, которую хотите отравить:" << '\n';
    int num;
    std::cin >> num;
    char* arr = new char[241];
    char* arr1 = new char[241];
    char* arr2 = new char[241];
    char* code = new char[6];
    char* code2 = new char[5];
    char* arryes = new char[3];

    int ost;
    int i = 0;
    int k = 241;
    int miu = num;
    int length = 5;

    while(miu > 0)
    {
        ost = miu % 3;
        miu /= 3;
        arr[i] = ost + '0';
        i++;

    }

    int quantity = 5 - i;

    for (int j = 0; j < quantity; j++)
        arr1[j] = '0';

    for (int j = 0; j < i; j++)
        arr1[quantity + j] = arr[i - j - 1];

    std::cout << "Введите 'yes', если хотите посмотреть результат 1 дня:" << '\n';
    std::cin.ignore();
    std::cin.getline(arryes, 4);
    if(arryes[0] == 'y' && arryes[1] == 'e' && arryes[2] == 's' && arryes[3] == '\0')
    {
        code = statisticdayone(arr1, code);
    }
    else
    {
        std::cout << "НЕВЕРНЫЙ ВВОД! Ну и ладно:" << '\n';
        code = statisticdayone(arr1, code);
    }
    std::cout << '\n';
    std::cout << "Введите 'yes', если хотите посмотреть результат 2 дня:" << '\n';
    std::cin.ignore();
    std::cin.getline(arryes, 4);
    if(arryes[0] == 'y' && arryes[1] == 'e' && arryes[2] == 's' && arryes[3] == '\0')
    {
        code = statisticdaytwo(arr1, code);
    }
    else
    {
        std::cout << "НЕВЕРНЫЙ ВВОД! Ну и ладно:" << '\n';
        code = statisticdaytwo(arr1, code);
    }
    std::cout << '\n';
    int meow;
    meow = tehnsistem(code, length);
        std::cout << "Номер отравленной бочки: Н" << ' ' << meow << '\n';
        std::cout << '\n';

    delete[] arr;
    delete[] arr1;
    delete[] arr2;

}

char* statisticdayone(char* arr1, char* code)
{
    std::cout << "Статистика прошедшего дня:" << '\n';
    for(int ö = 0; arr1[ö] != '\0'; ö++)
    {
        if(arr1[ö] == '0')
        {
            std::cout << "Раб" << " " << ö + 1 << " " << "Выжил" << '\n';
            //code[ö] = arr1[ö];A
        }
        if(arr1[ö] == '1')
        {
            std::cout << "Раб" << " " << ö + 1 << " " << "Отчислен" << '\n';
            //code[ö] = arr1[ö];
        }
        if(arr1[ö] == '2')
        {
            std::cout << "Раб" << " " << ö + 1 << " " << "Будет пить завтра" << '\n';
            //code[ö] = '?';
        }
    }

    int z = 0;
    std::cout << "Начальный код бочки:" << '\n';
    for(int j = 0; j < 5; j++)
    {
        if(arr1[j] == '0')
        {
            code[j] = arr1[j];
        }

        else if(arr1[j] == '1')
        {
            code[j] = arr1[j];
        }
        else{
            code[j] = '?';
        }
    }
    for(int j = 0; j  < 6; j++)
        {
            std::cout << code[j];
        }
    return code;
}
char* statisticdaytwo(char* arr1, char* code)
{
    std::cout << "Статистика второго дня:" << '\n';
    for(int ö = 0; arr1[ö] != '\0'; ö++)
    {
        if(arr1[ö] == '0')
        {
        std::cout << "Раб" << " " << ö + 1 << " " << "Выжил" << '\n';
        }
        if(arr1[ö] == '1')
        {
            std::cout << "Раб" << " " << ö + 1 << " " << "Умер в первый день" << '\n';
        }
        if(arr1[ö] == '2')
        {
            std::cout << "Раб" << " " << ö + 1 << " " << "Умер во второй день" << '\n';
        }
    }

    std::cout << "Итоговый код бочки: " << '\n';
    int k;

    for(int j = 0; j < 5; j++)
    {
        if(arr1[j] == '0') {
            code[j] = arr1[j];
        }
        else if(arr1[j] == '1') {
            code[j] = arr1[j];
        }
        else {
            code[j] = '2';
        }
    }

    code[5] = '\0';

    for(int j = 0; j  < 5; j++)
        std::cout << code[j];

    return code;
}

int tehnsistem(char* code, int length)
{
    int decimal = 0;
    for (int i = 0; i < length; ++i) {
        int digit = code[length - 1 - i] - '0';
        decimal += digit * pow(3, i);
}

return decimal;
}





