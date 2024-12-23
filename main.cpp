#include <iostream>
#include "Task_1.h"
#include "Task_2.h"
#include "Task_3.h"
#include "Task_4.h"
#include "Task_5.h"

int InputInt();

int main() {
    int choice;
    while (true) {
        std::cout << "\nДля выхода из программы введите - 0\n\n";
        std::cout <<  "Для выбора задания введите:\n1 - Задание 1\n2 - Задание 2\n3 - Задание 3\n4 - Задание 4\n5 - Задание 5\n";
        choice = InputInt();
        if (choice == 0) {
            std::cout << "Программа успешно завершена" << std::endl;
            return 0;
        }
        switch (choice) {
            case 1:
                Task_1();
            break;
            case 2:
                Task_2();
                    break;
            case 3:
                Task_3();
            break;
            case 4:
                Task_4();
            break;
            case 5:
                Task_5();
            break;
            default:
                std::cout << "НЕДОПУСТИМЫЙ ВВОД!!!\nПринимаются только значение 1,2,3\nВведите заново:" << std::endl;
        }
    }
}

int InputInt() {
    int x;
    bool flag = true;
    while (flag) {
        flag = false;
        std::cin.clear();
        std::cin >> x;
        while (std::cin.peek() != '\n') {
            if (std::cin.get() != ' ') flag = true;
            std::cin.clear();
        };
        if (flag) std::cout << ' ' << "НЕДОПУСТИМЫЙ ВВОД!\n";
    }
    return x;
}