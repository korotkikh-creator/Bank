#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H

#include "Account.h"
#include "Exceptions.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class AccountList {
    vector<Account> accounts;

public:
    void addUser(const Account& account); //проверить ссылкой (подать на вход ссылку)
    Account* searchByNumber(int number); //const
    bool deleteUser(const Account& account);
    Account& getFirstAccount();
    Account& getLastAccount();
    Account& operator [](int index);
    bool exists(const Account& account);
    int getSize();
    //геттеры и сеттеры
    friend ostream& operator <<(ostream& out, AccountList& accLst);
    friend istream& operator >>(istream& in, AccountList& accLst);
};


#endif