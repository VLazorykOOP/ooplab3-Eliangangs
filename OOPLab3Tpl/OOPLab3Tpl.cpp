#include <iostream>
#include "Lab3.h"
using namespace std;

int main()
{
    cout << " Lab #3 (14v)  !\n";

    int conv;
        while (true)
    {
        MenuTask();
        cout << "Введіть номер завдання: ";
        cin >> conv;

        switch (conv)
        {
        case 1:
            main1();
            break;

        case 2:
            main2();
            break;

        case 3:
            main3();
            break;

        case 0:
            cout << "Вихід із програми..." << endl;
            return 0;

        default:
            cout << "Невірний вибір! Спробуйте ще раз." << endl;
            break;
        }

        cout << "\nНатисніть Enter, щоб продовжити...\n";
        cin.ignore();
        cin.get();
    }

    return 0;
}

void MenuTask() {
    cout << "===== Виберіть завдання =====\n";
    cout << " 1. Task 1 — Parallelogram\n";
    cout << " 2. Task 2 — Vector\n";
    cout << " 3. Task 3 — Matrix\n";
    cout << " 0. Exit\n";
}