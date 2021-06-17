#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

/**
 * Основная единица для работы с пользователем
 * @param number
 * @param surname
 * @param name
 * @param middleName
 * @param balance
 */
class Account {
    std::string number;
    std::string surname;
    std::string name;
    std::string middleName;
    double balance;
    
public:
    Account();
    Account(std::string number, std::string surname, std::string name, std::string middleName, double balance);

/**
 * Реализация метода увеличения баланса на заданную величину в аргументах
 * @param increase
 */
    void increaseBalance(double increase);

/**
 * Реализация метода уменьшения баланса на заданную величину в аргументах
 * @param decrease
 */
    void decreaseBalance(double decrease);

/**
 * Реализация геттера
 * @return number
 */
    std::string getNumber() const;

/**
 * Реализация сеттера
 * @param number
 */
    void setNumber(std::string number);

/**
 * Реализация метода перевода денег (транзакции)
 * @param account
 * @param sum
 * @throws SumIsBiggerThanBalance если sum > текущего баланса у отправителя
 */
    void transaction(Account &account, double transact);

/**
 * Реализация оператора сравнения аккаунтов
 * @param account
 * @return true/false
 */
    bool operator==(const Account &account) const;


/**
 * Получение баланса аккаунта
 * @return double balance
 */    
    double getBalance() const;

/**
 * Перезаписывает баланс
 * @param balance
 */    
    void setBalance(double balance);

/**
 * Реализация потока вывода
 * @param os
 * @param account
 * @return os
 */
    friend std::ostream &operator<<(std::ostream &os, const Account &account);

/**
 * Реализация потока ввода
 * @param in
 * @param account
 * @return in
 */    
    friend std::istream &operator>>(std::istream &in, Account &account);
};

#endif
