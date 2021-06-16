#include "Bank.hpp"
using namespace std;

Bank::Bank() {
    this->code = 0;
}

Bank::Bank(int code) {
    this->code = code;
}

/**
 * создает новый аккаунт
 * @param number
 * @param surname
 * @param name
 * @param middleName
 * @param balance
 * @return acc
 */
Account Bank::createNewAccount(string number, string surname, string name, string middleName, double balance) {
    Account acc(number, surname, name, middleName, balance);
    this->accounts.addUser(acc);
    return acc;
}

/**
 *добавление аккаунта в список аккаунтов
 * @param account
 */
void Bank::addAccount(const Account &account) {
    this->accounts.addUser(account);
}

/**
 *удаление аккаунта из списка аккаунтов
 * @param account
 */
void Bank::deleteAccount(const Account &account) {
    this->accounts.deleteUser(account);
}

/**
 * проверка на существование
 * @param account
 * @return true/false
 */
bool Bank::existsAccount(const Account &account) {
    return this->accounts.exists(account);
}

/**
 * поиск по номеру
 * @param number
 * @return аккаунт
 */
Account *Bank::searchByNumber(string number) {
    return this->accounts.searchByNumber(number);
}

/**
 * перевод по номеру
 * @param senderNumber
 * @param receiveNumber
 * @param sum
 */
void Bank::transaction(string senderNumber, string receiveNumber, double sum) {
    
    Account *sender = this->accounts.searchByNumber(senderNumber);
    
    Account *receiver = this->accounts.searchByNumber(receiveNumber);
    
    if (sender == nullptr)
        throw UserNotFoundException("The sender wasn't found");
    if (receiver == nullptr)
        throw UserNotFoundException("The receiver wasn't found");
    
    if (sum > sender->getBalance())
        throw SumIsBiggerThanBalance("The sum is bigger than balance, you can't send money to another person");
    
    sender->decreaseBalance(sum);
    
    receiver->increaseBalance(sum);
}

//
/**
 * вывод в поток кода банка и списка его аккаунтов
 * @param out
 * @param bank
 * @return out
 */
ostream &operator<<(ostream &out, const Bank &bank) {
    return out << bank.code << endl << bank.accounts;
}


/**
 * ввод из потока кода и списка аккаунтов
 * @param in
 * @param bank
 * @return
 */
istream &operator>>(istream &in, Bank &bank) {
    return in >> bank.code >> bank.accounts;
}

int Bank::getCode() {
    return this->code;
}

bool Bank::operator==(const Bank &bank) const {
    return this->code == bank.code && this->accounts == bank.accounts;
}
