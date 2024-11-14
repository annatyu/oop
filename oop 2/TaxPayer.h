#pragma once
#include <iostream>
#include <string.h>
#include <stdexcept>
#include <string>
#include <iostream>
using namespace std;
class TaxPayer
{
private:
    char* inn;
    int year;
    double taxableIncome;//налогообладаемый 
    double nonTaxableIncome;//неналогообладаемый
    double taxableAmount;//итог суммы подоходного налога
    double totalIncome;//общая сумма дохода
    const double taxRate;//процент подоходного налога

public:
    // Конструктор
    TaxPayer(const char* inn, int year);

    // Деструктор
    ~TaxPayer();

    // Селекторы
    const char* getINN() const;

    int getYear() const;

    double getTaxableIncome() const;

    double getNonTaxableIncome() const;

    double getTaxableAmount() const;

    double getTotalIncome() const;

    double getTaxRate() const;

    // Метод вывода всех параметров на консоль
    void displayInfo() const;

    // Метод добавления статьи дохода
    void addIncome(double amount, bool isTaxable);

private:

    void setINN(const char* newINN);


    void setYear(int newYear);

    void updateTaxableAmount();

    void updateTotalIncome();
};


