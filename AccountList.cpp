#include "AccountList.h"

void AccountList::addUser(const Account& account) {
    if (searchByNumber(account.getNumber()) != nullptr)
        throw UserExistsException("The user with this number is already added");
    this->accounts.push_back(account);
}

Account* AccountList::searchByNumber(int number) {
    for (int i = 0; i < this->accounts.size(); i++) {
        if (this->accounts[i].getNumber() == number)
            return &this->accounts[i];
    }
    return nullptr;
}

bool AccountList::deleteUser(const Account& account) {
    if (this->accounts.size() == 0)
        throw EmptyListException("The list is empty");
    vector<Account>::iterator it = find(this->accounts.begin(), this->accounts.end(), account);
    if (it == this->accounts.end())
        return false;
    this->accounts.erase(it);
    return true;
}

Account& AccountList::getFirstAccount() {
    if (this->accounts.size() == 0)
        throw EmptyListException("The list is empty");
    return this->accounts[0];
}

Account& AccountList::getLastAccount() {
    if (this->accounts.size() == 0)
        throw EmptyListException("The list is empty");
    return this->accounts[this->accounts.size() - 1];
}

Account& AccountList::operator[] (int index) {
    if (index < 0 || index >= this->accounts.size())
        throw IndexOfRangeException("Wrong index");
    return this->accounts[index];
}

bool AccountList::exists(const Account& account) {
    for (int i = 0; i < this->accounts.size(); i++) {
        if (this->accounts[i] == account)
            return true;
    }
    return false;
}

int AccountList::getSize() {
    if (this->accounts.size() == 0)
        throw EmptyListException("The list is empty");
    return this->accounts.size();
}

ostream& operator <<(ostream& out, AccountList& accLst) {
    for (int i = 0; i < accLst.getSize(); i++)
        out << accLst.accounts[i] << "\n";
    return out;
}

istream& operator >>(istream& in, AccountList& accLst) {
    for (int i = 0; i < accLst.getSize(); i++)
        in >> accLst.accounts[i];
    return in;
}