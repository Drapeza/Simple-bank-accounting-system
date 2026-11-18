#include <iostream>
#include <windows.h>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "items.h"

void UncountItem::setUncountItemAmount()
{
    double amount;
    while (true)
    {
        std::cout << "\nВведите количество в метрах/литрах кубических: ";
        std::cin >> amount;

        if (std::cin.good())
        {
            std::cin.ignore(1000, '\n');
            break;
        }

        std::cin.clear();
        std::cout << "\nОшибка ввода данных!\n";
        std::cin.ignore(1000, '\n');
    }

    UncountItem::uncountItemAmount = amount;
}

double UncountItem::inputAmount(double maxAmount)
{
    double amount;
    while (true)
    {
        std::cout << "\nВведите количество (в единицах из названия товара, доступно " << maxAmount << "): ";
        std::cin >> amount;

        if (std::cin.good() && amount > 0 && amount <= maxAmount)
        {
            std::cin.ignore(1000, '\n');
            break;
        }

        std::cin.clear();
        std::cout << "\nОшибка ввода данных! Количество должно быть больше нуля и не больше остатка.\n";
        std::cin.ignore(1000, '\n');
    }

    return amount;
}

void CountItem::setCountItemAmount()
{
    int amount;
    while (true)
    {
        std::cout << "\nВведите количество в штуках: ";
        std::cin >> amount;

        if (std::cin.good())
        {
            std::cin.ignore(1000, '\n');
            break;
        }

        std::cin.clear();
        std::cout << "\nОшибка ввода данных!";
        std::cin.ignore(1000, '\n');
    }

    CountItem::countItemAmount = amount;
}

double CountItem::inputAmount(double maxAmount)
{
    int amount;
    while (true)
    {
        std::cout << "\nВведите количество в штуках (доступно " << maxAmount << "): ";
        std::cin >> amount;

        if (std::cin.good() && amount > 0 && amount <= maxAmount)
        {
            std::cin.ignore(1000, '\n');
            break;
        }

        std::cin.clear();
        std::cout << "\nОшибка ввода данных! Количество должно быть целым, больше нуля и не больше остатка.\n";
        std::cin.ignore(1000, '\n');
    }

    return amount;
}