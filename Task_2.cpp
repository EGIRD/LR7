#include "Task_2.h"
#include <iostream>
#include <string>
#include <algorithm>

std::string ConvertToBinary(int);
std::string Direct(const std::string&);
std::string Back(const std::string&);
std::string Addition(const std::string&, const std::string&);
std::string BackDirect(const std::string&);
int InputInt();

void Task_2() {
    long long number1, number2;
    std::string str1, str2, sum;

    std::cout << "Данная программа выполняет сумму двоичных чисел,заданных в естественной форме.\n"
                 "При этом сложение происходит в обратном коде, вывод в прямом коде.\nВведите числа:\n\nПервое число:";
    number1 = InputInt();
    //std::cin >> number1;

    std::cout << "Второе число:";
    number2 = InputInt();
    //std::cin >> number2;

    str1 = ConvertToBinary(number1);
    str2 = ConvertToBinary(number2);

    if (str1[0] == '1') str1 = Direct(str1);
    if (str2[0] == '1') str2 = Direct(str2);

    sum = Addition(str1, str2);
    std::cout << "\nРезультат: " << BackDirect(sum) << std::endl;
}

std::string ConvertToBinary(int number) // Cложность алгоритма: O(log n)
{
    std::string strn;
    bool sign = false;

    if (number < 0) {
        sign = true;
        number = -number;
    }

    do {
        strn += (number % 2) ? '1' : '0';
        number /= 2;
    } while (number > 0);

    if (strn.empty()) strn = "0";
    if (sign) strn += '1';

    std::reverse(strn.begin(), strn.end());

    return strn;
}

std::string Direct(const std::string& str) // Cложность алгоритма: O(log n)
{
    std::string inverted = str;
    for (char& c : inverted)
        c = (c == '1') ? '0' : '1';

    return inverted;
}

std::string Back(const std::string& str) // Cложность алгоритма: O(log n)
{
    std::string result = str;
    int carry = 1;

    for (int i = result.size() - 1; i >= 0 && carry; --i) {
        if (result[i] == '1') {
            result[i] = '0';
        } else {
            result[i] = '1';
            carry = 0;
        }
    }

    if (carry) result = '1' + result;

    return result;
}

std::string Addition(const std::string& str1, const std::string& str2) // Cложность алгоритма: O(log n)
{
    std::string result;
    int carry = 0;
    int i = str1.size() - 1, j = str2.size() - 1;

    while (i >= 0 || carry) {
        int sum = carry;
        if (i >= 0) sum += (str1[i--] - '0');
        if (j >= 0) sum += (str2[j--] - '0');
        result += (sum % 2) + '0';
        carry = sum / 2;
    }
    std::reverse(result.begin(), result.end());

    return result;
}

std::string BackDirect(const std::string& str) // Cложность алгоритма: O(log n)
{
    if (str[0] == '1') {
        std::string inverted = Direct(str);
        return Back(inverted);
    }
    return str;
}