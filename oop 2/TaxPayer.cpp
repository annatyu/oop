#include "TaxPayer.h"

// Конструктор

 TaxPayer::TaxPayer(const char* inn, int year)
    : taxableIncome(0),
    nonTaxableIncome(0),
    taxableAmount(0),
    totalIncome(0),
    taxRate(0.13) {
    setINN(inn);
    setYear(year);
}

 //TaxPayer::TaxPayer(double taxable, double nonTaxable) 
 //{
   //setTaxableIncome(taxable),
   //setNonTaxableIncome(nonTaxable)
 //}

 // Деструктор

 TaxPayer::~TaxPayer() {
     delete[] inn;
 }

 // Геттеры

 inline const char* TaxPayer::getINN() const {
     return inn;
 }

 inline int TaxPayer::getYear() const {
     return year;
 }

 inline double TaxPayer::getTaxableIncome() const {
     return taxableIncome;
 }

 inline double TaxPayer::getNonTaxableIncome() const {
     return nonTaxableIncome;
 }

 inline double TaxPayer::getTaxableAmount() const {
     return taxableAmount;
 }

 inline double TaxPayer::getTotalIncome() const {
     return totalIncome;
 }

 inline double TaxPayer::getTaxRate() const {
     return taxRate;
 }

 // Метод вывода всех параметров на консоль

 void TaxPayer::displayInfo() const {
     cout << "INN " << getINN() << endl;
     cout << "YEAR " << getYear() << endl;
     cout << "NALOGOOBLAD_DOHOD " << getTaxableIncome() << endl;
     cout << "NENALOGOOBLAD_DOHOD " << getNonTaxableIncome() << endl;
     cout << "ITOG_SUMM_DOHOD_NALOGA " << getTaxableAmount() << endl;
     cout << "ITOG_SUM_DOHODA " << getTotalIncome() << endl;
     cout << "PERSENT_DOHOD_NALOGA " << getTaxRate() * 100 << "%" << endl;
 }

 // Метод добавления статьи дохода

 inline void TaxPayer::addIncome(double amount, bool isTaxable) {
     if (amount <= 0) {
         throw invalid_argument("The income should be positive.");
     }

     if (isTaxable) {
         taxableIncome += amount;
     }
     else {
         nonTaxableIncome += amount;
     }

     updateTaxableAmount();
     updateTotalIncome();
 }
 //сеттеры
 void TaxPayer::setINN(const char* newINN) {
     if (newINN == nullptr) {
         throw invalid_argument("The INN cannot be nullptr."); // Исключение, если указатель равен nullptr
     }

     if (strlen(newINN) != 10) { // Проверка длины ИНН
         throw invalid_argument("The INN must consist of 10 characters."); // Исключение, если длина не 10
     }

     inn = new char[strlen(newINN) + 1]; // Выделение памяти под ИНН
     strcpy_s(inn, strlen(newINN) + 1, newINN); // Копирование ИНН
 }
// void TaxPayer::setTaxableIncome()

 void TaxPayer::setYear(int newYear) {
     if (newYear < 2000 || newYear > 2100) {
         throw invalid_argument("Invalid year value.");
     }
     year = newYear;
 }

 void TaxPayer::updateTaxableAmount() {
     taxableAmount = taxableIncome * taxRate;
 }

 void TaxPayer::updateTotalIncome() {
     totalIncome = taxableIncome + nonTaxableIncome;
 }




