#ifndef ACCOUNTLIST_H
#define ACCOUNTLIST_H

#include "Account.hpp"
#include "Exceptions.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

/**
 * Класс всех аккаунтов (список аккаунтов)
 */
class AccountList {
    std::vector<Account> accounts;

public:
    /**
     * Метод добавления нового аккаунта в список всех аккаунтов
     * @param account
     * @throws UserExistsException если указатель не указывает в пустоту при поиске searchByNumber
    */
    void addUser(const Account &account);

    /**
     * Метод поиска аккаунта по его номеру
     * @param number
     * @return указатель на аккаунт
     */
    Account *searchByNumber(std::string number);

    /**
     * Метод удаления аккаунта из списка всех аккаунтов
     * @param account
     * @return true/false
     * @throws EmptyListException если размер списка аккаунтов равен 0
     */
    bool deleteUser(const Account &account);

    /**
     * Для получения начального элемента в списке
     * @return указатель this
     * @throws EmptyListException если размер списка аккаунтов равен 0
     */
    Account &getFirstAccount();

    /**
     * Для получения последнего элемента в списке
     * @return указатель this
     * @throws EmptyListException если размер списка аккаунтов равен 0
     */
    Account &getLastAccount();

    /**
     * Перегрузка оператора индексации
     * @param index
     * @return account[index]
     * @throws IndexOfRangeException если индекс вышел за пределы индексации массива
     */
    Account &operator[](int index);

    /**
     * Проверка на существование аккаунта в списке аккаунтов
     * @param account
     * @return true/false
     */
    bool exists(const Account &account);

    /**
     * Метод определения размера списка аккаунтов
     * @return int accounts.size()
     * @throws EmptyListException если размер списка аккаунтов равен 0
     */
    int getSize() const;

    /**
     * Оператор сравнения для AccountList
     * @param accountList
     * @return true/false
     */
    bool operator==(const AccountList &accountList) const;

    /**
     * ostream поток на вывод
     * @param out
     * @param accLst
     * @return out
     */
    friend std::ostream &operator<<(std::ostream &out, const AccountList &accLst);

    /**
     * istream поток на ввод
     * @param in
     * @param accLst
     * @return in
     */
    friend std::istream &operator>>(std::istream &in, AccountList &accLst);
};


#endif
