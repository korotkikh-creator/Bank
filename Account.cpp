#include "Account.hpp"
#include "AccountList.hpp"

using namespace std;

Account::Account() {
    this->balance = 0;
}

/**
 * Основная единица для работы с пользователем
 * @param number
 * @param surname
 * @param name
 * @param middleName
 * @param balance
 */
Account::Account(string number, string surname, string name, string middleName, double balance) {
    this->number = number;
    this->surname = surname;
    this->name = name;
    this->middleName = middleName;
    this->balance = balance;
}

/**
 * Реализация метода увеличения баланса на заданную величину в аргументах
 * @param increase
 */
void Account::increaseBalance(double increase) {
    this->balance += increase;
}

/**
 * Реализация метода уменьшения баланса на заданную величину в аргументах
 * @param decrease
 */
void Account::decreaseBalance(double decrease) {
    this->balance -= decrease;
}

/**
 * Реализация геттера
 * @return number
 */
string Account::getNumber() const {
    return this->number;
}

/**
 * Реализация сеттера
 * @param number
 */
void Account::setNumber(string number) {
    this->number = number;
}

/**
 * Реализация метода перевода денег (транзакции)
 * @param account
 * @param sum
 * @throws SumIsBiggerThanBalance если sum > текущего баланса у отправителя
 */
void Account::transaction(Account &account, double sum) {
    if(this->balance < sum)
        throw SumIsBiggerThanBalance("Insufficient sum");
    this->decreaseBalance(sum);
    account.increaseBalance(sum);
}

/**
 * Реализация оператора сравнения аккаунтов
 * @param account
 * @return true/false
 */
bool Account::operator==(const Account &account) const {
    return this->number == account.number && this->surname == account.surname && this->name == account.name
           && this->middleName == account.middleName && this->balance == account.balance;
}

/**
 * Получение баланса аккаунта
 * @return double balance
 */
double Account::getBalance() const {
    return this->balance;
}

/**
 * Перезаписывает баланс
 * @param balance
 */
void Account::setBalance(double balance) {
    this->balance = balance;
}

/**
 * Реализация потока вывода
 * @param os
 * @param account
 * @return os
 */
ostream &operator<<(ostream &os, const Account &account) {
    return os << account.number << " " << account.surname << " " << account.name << " " << account.middleName << " "
              << account.balance;
}

/**
 * Реализация потока ввода
 * @param in
 * @param account
 * @return in
 */
istream &operator>>(istream &in, Account &account) {
    return in >> account.number >> account.surname >> account.name >> account.middleName >> account.balance;
}
