#include "Task_3.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

int charToValue(char);
char valueToChar(int);
std::string add(const std::string&, const std::string&, int);
std::string subtract(const std::string&, const std::string&, int);
int InputInt();

void Task_3() {
    int base;
    std::string num1, num2;
    char operation;

    std::cout << "Введите основание системы счисления (2-36): ";
    base = InputInt();//std::cin >> base;

    if (base < 2 || base > 36) std::cout << "Некорректное основание системы счисления!\n";

    std::cout << "Введите первое число: ";
    num1 = InputInt();

    std::cout << "Введите второе число: ";
    num2  = InputInt();

    std::cout << "Введите операцию (+ или -): ";
    std::cin >> operation;

    if (operation == '+') {
        std::string sum = add(num1, num2, base);
        std::cout << "Результат сложения: " << sum << std::endl;
    } else if (operation == '-') {
        std::string difference = subtract(num1, num2, base);
        std::cout << "Результат вычитания: " << difference << std::endl;
    } else {
        std::cerr << "Некорректная операция!" << std::endl;
    }

}

int charToValue(char c)
{
    if (isdigit(c)) {
        return c - '0';
    } else {
        return toupper(c) - 'A' + 10;
    }
}

char valueToChar(int value)
{
    if (value < 10) {
        return '0' + value;
    } else {
        return 'A' + (value - 10);
    }
}

std::string add(const std::string& num1, const std::string& num2, int base)
{
    std::string result;
    int carry = 0;
    int maxLength = std::max(num1.length(), num2.length());

    for (int i = 0; i < maxLength || carry; ++i) {
        int digit1 = (i < num1.length()) ? charToValue(num1[num1.length() - 1 - i]) : 0;
        int digit2 = (i < num2.length()) ? charToValue(num2[num2.length() - 1 - i]) : 0;

        int sum = digit1 + digit2 + carry;
        carry = sum / base;
        result += valueToChar(sum % base);
    }
    std::reverse(result.begin(), result.end());

    return result;
}

std::string subtract(const std::string& num1, const std::string& num2, int base)
{
    std::string result;
    int borrow = 0;
    int maxLength = std::max(num1.length(), num2.length());

    for (int i = 0; i < maxLength; ++i) {
        int digit1 = (i < num1.length()) ? charToValue(num1[num1.length() - 1 - i]) : 0;
        int digit2 = (i < num2.length()) ? charToValue(num2[num2.length() - 1 - i]) : 0;

        digit1 -= borrow;
        if (digit1 < digit2) {
            digit1 += base;
            borrow = 1;
        } else {
            borrow = 0;
        }

        result += valueToChar(digit1 - digit2);
    }

    while (result.length() > 1 && result.back() == '0') {
        result.pop_back();
    }
    std::reverse(result.begin(), result.end());

    return result.empty() ? "0" : result;
}