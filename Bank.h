#ifndef BANK_H
#define BANK_H

#include "AccountList.h"

using namespace std;

//класс банка
class Bank {
    //поля
    //код банка
	int code;
	//список аккаунтов которые зарегистрированы в банке
	AccountList accounts;

public:
    //конструктор по умолчанию
	Bank();
    //конструктор с параметром кода банка
	Bank(int code);

	//метод создания нового аккаунта
	Account createNewAccount(string number, string surname, string name, string middleName, double balance);

	//метод добавления нового аккаунта
	void addAccount(const Account& account);

	//удаление аккаунта
	void deleteAccount(const Account& account);

	//проверка на существование
	bool existsAccount(const Account& account);

	//получение индекса аккаунта в списке
	int GetIndex(const Account& account);

	//метод поиска аккаунта по номеру
	Account* searchByNumber(string number);

	//метод перевода денег между счетами по их номерам
	void transaction(string senderNumber, string receiveNumber, double sum);

	int getCode();

	//оператор вывода
	friend ostream& operator << (ostream& out, const Bank& bank);

	//оператор ввода
	friend istream& operator >> (istream& in, Bank& bank);
};
#endif
