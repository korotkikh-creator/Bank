#ifndef BANK_H
#define BANK_H

#include "AccountList.hpp"


/**
 * класс банка
 */
class Bank {

    int code;

    AccountList accounts;

public:

    Bank();



    Bank(int code);


    /**
     * метод создания нового аккаунта
     * @param number
     * @param surname
     * @param name
     * @param middleName
     * @param balance
     * @return
     */
    Account createNewAccount(std::string number, std::string surname, std::string name, std::string middleName, double balance);


    /**
     * метод добавления нового аккаунта
     * @param account
     */
    void addAccount(const Account &account);


    /**
     * удаление аккаунта
     * @param account
     */
    void deleteAccount(const Account &account);


    /**
     * проверка на существование
     * @param account
     * @return true/false
     */
    bool existsAccount(const Account &account);

    int GetIndex(const Account &account);

    /**
     * метод поиска аккунта по номеру
     * @param number
     * @return возвращается ссылка на аккаунт
     */
    Account *searchByNumber(std::string number);

    /**
     * метод перевода денег между счетами по их номерам
     * @param senderNumber
     * @param receiveNumber
     * @param sum
     */
    void transaction(std::string senderNumber, std::string receiveNumber, double sum);

    int getCode();

    bool operator==(const Bank &bank) const;

    /**
     * оператор вывода
     * @param out
     * @param bank
     * @return out
     */
    friend std::ostream &operator<<(std::ostream &out, const Bank &bank);

    /**
     * оператор ввода
     * @param in
     * @param bank
     * @return in
     */
    friend std::istream &operator>>(std::istream &in, Bank &bank);
};

#endif
