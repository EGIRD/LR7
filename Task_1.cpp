#include "Task_1.h"
#include <iostream>
#include <string>
#include <cmath>

void Task_1() { // Общая сложность алгоритма: O(n);
    std::string strn;
    long long number, i,length;

    std::cout << "Данная программа переводит число из обратного кода в естественную форму.\n";
    std::cout << "Введите число в форме обратного кода: ";

    std::cin >> strn;
    length = strn.length();

    if (strn[0] == '1')
        for (i = 1; i < length; i++)
            if (strn[i] == '0')
                strn[i] = '1';
            else
                strn[i] = '0';

    for (number = 0, i = 1; i < length; i++)
        if (strn[i] == '1')
            number += pow(2, length - i - 1);

    std::cout << "Число в естественной форме: " << number << std::endl;
}