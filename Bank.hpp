#ifndef BANK_H
#define BANK_H

#include "AccountList.hpp"

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
    Account createNewAccount(std::string number, std::string surname, std::string name, std::string middleName, double balance);

    //метод добавления нового аккаунта
    void addAccount(const Account &account);

    //удаление аккаунта
    void deleteAccount(const Account &account);

    //проверка на существование
    bool existsAccount(const Account &account);

    //получение индекса аккаунта в списке
    int GetIndex(const Account &account);

    //метод поиска аккаунта по номеру
    Account *searchByNumber(std::string number);

    //метод перевода денег между счетами по их номерам
    void transaction(std::string senderNumber, std::string receiveNumber, double sum);

    int getCode();

    bool operator==(const Bank &bank) const;

    //оператор вывода
    friend std::ostream &operator<<(std::ostream &out, const Bank &bank);

    //оператор ввода
    friend std::istream &operator>>(std::istream &in, Bank &bank);
};

#endif
