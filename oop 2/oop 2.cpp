#pragma once

#include <iostream>
#include <string.h>
#include <stdexcept>
#include <string>
#include <iostream>
#include "TaxPayer.h"

using namespace std;




//
//class TaxPayer2 {
//private:
//    char* inn;
//    int year;
//    double taxableIncome;//налогообладаемый 
//    double nonTaxableIncome;//неналогообладаемый
//    double taxableAmount;//итог суммы подоходного налога
//    double totalIncome;//общая сумма дохода
//    const double taxRate;//процент подоходного налога
//
//public:
//    // Конструктор
//    TaxPayer2(const char* inn, int year)
//        : taxableIncome(0), 
//        nonTaxableIncome(0), 
//        taxableAmount(0), 
//        totalIncome(0), 
//        taxRate(0.13) {
//        setINN(inn);
//        setYear(year);
//    }
// //ПЕРЕГРУЗКА КОНСТРУКТОРА
//     TaxPayer2(double taxable, double nonTaxable);
//      : 
//      taxableIncome(taxable), 
//        nonTaxableIncome(nonTaxable)
//
//    // Деструктор
//    ~TaxPayer2() {
//        delete[] inn;
//    }
//
//    // Селекторы
//    const char* getINN() const {
//        return inn;
//    }
//
//    int getYear() const {
//        return year;
//    }
//
//    double getTaxableIncome() const {
//        return taxableIncome;
//    }
//
//    double getNonTaxableIncome() const {
//        return nonTaxableIncome;
//    }
//
//    double getTaxableAmount() const {
//        return taxableAmount;
//    }
//
//    double getTotalIncome() const {
//        return totalIncome;
//    }
//
//    double getTaxRate() const {
//        return taxRate;
//    }
//
//    // Метод вывода всех параметров на консоль
//    void displayInfo() const {
//        cout << "INN " << getINN() << endl;
//        cout << "YEAR " << getYear() << endl;
//        cout << "NALOGOOBLAD_DOHOD " << getTaxableIncome() << endl;
//        cout << "NENALOGOOBLAD_DOHOD " << getNonTaxableIncome() << endl;
//        cout << "ITOG_SUMM_DOHOD_NALOGA " << getTaxableAmount() << endl;
//        cout << "ITOG_SUM_DOHODA " << getTotalIncome() << endl;
//        cout << "PERSENT_DOHOD_NALOGA " << getTaxRate() * 100 << "%" << endl;
//    }
//
//    // Метод добавления статьи дохода
//    void addIncome(double amount, bool isTaxable) {
//        if (amount <= 0) {
//            throw invalid_argument("The income should be positive.");
//        }
//
//        if (isTaxable) {
//            taxableIncome += amount;
//        }
//        else {
//            nonTaxableIncome += amount;
//        }
//
//        updateTaxableAmount();
//        updateTotalIncome();
//    }
//
//private:
//
//    void setINN(const char* newINN) {
//        if (newINN == nullptr) { 
//            throw invalid_argument("The INN cannot be nullptr."); // Исключение, если указатель равен nullptr
//        }
//
//        if (strlen(newINN) != 10) { // Проверка длины ИНН
//            throw invalid_argument("The INN must consist of 10 characters."); // Исключение, если длина не 10
//        }
//
//        inn = new char[strlen(newINN) + 1]; // Выделение памяти под ИНН
//        strcpy_s(inn, strlen(newINN) + 1, newINN); // Копирование ИНН
//    }
//\
//
//    void setYear(int newYear) {
//        if (newYear < 2000 || newYear > 2100) {
//            throw invalid_argument("Invalid year value.");
//        }
//        year = newYear;
//    }
//
//    void updateTaxableAmount() {
//        taxableAmount = taxableIncome * taxRate;
//    }
//
//    void updateTotalIncome() {
//        totalIncome = taxableIncome + nonTaxableIncome;
//    }
//};
//ПЕРЕГРУЗКА КОНСТРУКТОРА
//TaxPayer2(double taxable, double nonTaxable);
//: {taxableIncome(taxable), 
//nonTaxableIncome(nonTaxable)}


int main() {
    try {
        TaxPayer taxpayer("1234567890", 2023);
        taxpayer.addIncome(100000, true); // Налогооблагаемый доход
        taxpayer.addIncome(50000, false); // Неналогооблагаемый доход
        taxpayer.displayInfo();
    }
    catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}
