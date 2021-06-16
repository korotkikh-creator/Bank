#include "Bank.hpp"
using namespace std;

Bank::Bank() {
    this->code = 0;
}

Bank::Bank(int code) {
    this->code = code;
}

//получает на вход аругменты и создает аккаунта с этими данными и добавляет в список аккаунтов
Account Bank::createNewAccount(string number, string surname, string name, string middleName, double balance) {
    Account acc(number, surname, name, middleName, balance);
    this->accounts.addUser(acc);
    return acc;
}

//добавление аккаунта в список аккаунтов
void Bank::addAccount(const Account &account) {
    this->accounts.addUser(account);
}

//удаление аккаунта из списка аккаунтов
void Bank::deleteAccount(const Account &account) {
    this->accounts.deleteUser(account);
}

//проверка на существование
bool Bank::existsAccount(const Account &account) {
    return this->accounts.exists(account);
}

//поиск по номеру
Account *Bank::searchByNumber(string number) {
    return this->accounts.searchByNumber(number);
}

//перевод по номеру
void Bank::transaction(string senderNumber, string receiveNumber, double sum) {
    //поиск аккаунта откуда перевод
    Account *sender = this->accounts.searchByNumber(senderNumber);
    //поиск аккаунта куда перевод
    Account *receiver = this->accounts.searchByNumber(receiveNumber);
    //если отправитель или получатель не найдены то бросается исключение
    if (sender == nullptr)
        throw UserNotFoundException("The sender wasn't found");
    if (receiver == nullptr)
        throw UserNotFoundException("The receiver wasn't found");
    //если суммы на счету не достаточно для перевода то бросается исключение
    if (sum > sender->getBalance())
        throw SumIsBiggerThanBalance("The sum is bigger than balance, you can't send money to another person");
    //у отправителя уменьшается баланс на значение суммы
    sender->decreaseBalance(sum);
    //у получателя увеличивается баланс на значение суммы
    receiver->increaseBalance(sum);
}

//вывод в поток кода банка и списка его аккаунтов
ostream &operator<<(ostream &out, const Bank &bank) {
    return out << bank.code << endl << bank.accounts;
}

//ввод из потока кода и списка аккаунтов
istream &operator>>(istream &in, Bank &bank) {
    return in >> bank.code >> bank.accounts;
}

int Bank::getCode() {
    return this->code;
}

bool Bank::operator==(const Bank &bank) const {
    return this->code == bank.code && this->accounts == bank.accounts;
}
