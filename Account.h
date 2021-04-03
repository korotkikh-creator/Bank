#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {
    int number;
    string surname;
    string name;
    string middleName;
    double balance;

public:
    Account();
    Account(int number, string surname, string name, string middleName, double balance);
    void increaseBalance(double increase);
    void decreaseBalance(double decrease);
    int getNumber() const;
    void setNumber(int number);
    //остальные геттеры/сеттеры
    void transaction(Account& account, double transact);
    bool operator == (const Account& account);
    friend ostream& operator <<(ostream& os, const Account& account);
    friend istream& operator >>(istream& in, Account& account);
};

#endif
