#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H

#include "Account.h"
#include "Exceptions.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//класс который содержит в себе список всех аккаунтов
class AccountList {
    //вектор - список
	vector<Account> accounts;

public:
    //Метод добавления нового аккаунта в список всех аккаунтов
	void addUser(const Account& account);

    //Метод поиска аккаунта по его номеру
	Account* searchByNumber(string number);

	//Метод удаления аккаунта из списка всех аккаунтов
	bool deleteUser(const Account& account);

	//Метод получения первого аккаунта из списка
	Account& getFirstAccount();

	//Метод получения последнего аккаунта из списка
	Account& getLastAccount();

	//Перегрузка оператора индексации
	Account& operator [](int index);

	//Метод проверки на существование аккаунта
	bool exists(const Account& account);

	//Метод получения размера списка (количество аккаунтов)
	int getSize() const;

	//оператор вывода
	friend ostream& operator <<(ostream& out, const AccountList& accLst);
	//опратор ввода
	friend istream& operator >>(istream& in, AccountList& accLst);
};


#endif