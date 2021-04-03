#include "Account.h"

Account::Account() {
    this->number = 0;
    this->balance = 0;
}

Account::Account(int number, string surname, string name, string middleName, double balance) {
    this->number = number;
    this->surname = surname;
    this->name = name;
    this->middleName = middleName;
    this->balance = balance;
}

void Account::increaseBalance(double increase) {
    this->balance += increase;
}

void Account::decreaseBalance(double decrease) {
    this->balance -= decrease;
}

int Account::getNumber() const {
    return this->number;
}

void Account::setNumber(int number) {
    this->number = number;
}

//остальные геттеры/сеттеры

void Account::transaction(Account& account, double sum) {
    this->decreaseBalance(sum);
    account.increaseBalance(sum);
}

bool Account::operator==(const Account& account) {
    return this->number == account.number && this->surname == account.surname && this->name == account.name
           && this->middleName == account.middleName && this->balance == account.balance;
}

ostream& operator <<(ostream& os, const Account& account) {
    return os << "Number: " << account.number << ", Surname: " << account.surname << ", Name: " << account.name
              << ", Middle Name: " << account.middleName << ", " << "Balance: " << account.balance;
}

istream& operator >>(istream& in, Account& account) {
    return in >> account.number >> account.surname >> account.name >> account.middleName >> account.balance;
}