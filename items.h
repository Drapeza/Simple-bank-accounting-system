#pragma once
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>

class Item
{
protected:
    std::string itemName;
    double price;

public:
    Item()
    {
        itemName = "None";
        price = 0.0;
    }
    Item(const char *name, double price) : itemName(name), price(price) {}
    std::string getName() const { return itemName; }
    double getPrice() const { return price; }
    void setName(const char *name) { this->itemName = name; }
    void setPrice(double price) { this->price = price; }
    void showInfo()
    {
        std::cout << "Название: " << itemName << ", цена: " << price << '\n';
    }
    virtual double getAmount() const = 0;
    virtual double inputAmount(double maxAmount) = 0;
    virtual void decreaseAmount(double amount) = 0;
    virtual ~Item() {}
};

class UncountItem : public Item
{
protected:
    double uncountItemAmount;

public:
    UncountItem(const char *uncountItemName, double price, double uncountItemAmount = 0.0) : Item(uncountItemName, price), uncountItemAmount(uncountItemAmount) {}

    void setUncountItemAmount();
    double getAmount() const override { return uncountItemAmount; }
    double inputAmount(double maxAmount) override;
    void decreaseAmount(double amount) override { uncountItemAmount -= amount; }
    ~UncountItem() {}
};



class CountItem : public Item
{
protected:
    int countItemAmount;

public:
    CountItem(const char *countItemName, double price, int countItemAmount = 0) : Item(countItemName, price), countItemAmount(countItemAmount) {}

    void setCountItemAmount();
    double getAmount() const override { return countItemAmount; }
    double inputAmount(double maxAmount) override;
    void decreaseAmount(double amount) override { countItemAmount -= (int)amount; }
    ~CountItem() {}
};
