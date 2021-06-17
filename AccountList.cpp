#include "AccountList.hpp"
using namespace std;

/**
 * Метод добавления нового аккаунта в список всех аккаунтов
 * @param account
 * @throws UserExistsException если указатель не указывает в пустоту при поиске searchByNumber
 */
void AccountList::addUser(const Account& account) {
	if (searchByNumber(account.getNumber()) != nullptr)
		throw UserExistsException("The user with this number is already added");
	this->accounts.push_back(account);
}

/**
 * Метод поиска аккаунта по его номеру
 * @param number
 * @return указатель на аккаунт
 */
Account* AccountList::searchByNumber(string number) {
	for (int i = 0; i < this->accounts.size(); i++) {
		if (this->accounts[i].getNumber() == number)
			return &this->accounts[i];
	}
	return nullptr;
}

/**
 * Метод удаления аккаунта из списка всех аккаунтов
 * @param account
 * @return true/false
 * @throws EmptyListException если размер списка аккаунтов равен 0
 */
bool AccountList::deleteUser(const Account& account) {
	if (this->accounts.size() == 0)
		throw EmptyListException("The list is empty");
	vector<Account>::iterator it = find(this->accounts.begin(), this->accounts.end(), account);
	if (it == this->accounts.end())
		return false;
	this->accounts.erase(it);
	return true;
}

/**
 * Для получения начального элемента в списке
 * @return указатель this
 */
Account& AccountList::getFirstAccount() {
	if (this->accounts.size() == 0)
		throw EmptyListException("The list is empty");
	return this->accounts[0];
}

/**
 * Для получения последнего элемента в списке
 * @return указатель this
 */
Account& AccountList::getLastAccount() {
	if (this->accounts.size() == 0)
		throw EmptyListException("The list is empty");
	return this->accounts[this->accounts.size() - 1];
}

/**
 * Перегрузка оператора индексации
 * @param index
 * @return account[index]
 */
Account& AccountList::operator[] (int index) {
	if (index < 0 || index >= this->accounts.size())
		throw IndexOfRangeException("Wrong index");
	return this->accounts[index];
}

/**
 * Проверка на существование аккаунта в списке аккаунтов
 * @param account
 * @return true/false
 */
bool AccountList::exists(const Account& account) {
	for (int i = 0; i < this->accounts.size(); i++) {
		if (this->accounts[i] == account)
			return true;
	}
	return false;
}

/**
 * Метод определения размера списка аккаунтов
 * @return accounts.size()
 * @throws EmptyListException если размер списка аккаунтов равен 0
 */
int AccountList::getSize() const {
	if (this->accounts.size() == 0)
		throw EmptyListException("The list is empty");
	return this->accounts.size();
}

/**
 * ostream поток на вывод
 * @param out
 * @param accLst
 * @return out
 */
ostream& operator <<(ostream& out, const AccountList& accLst) {
	for (int i = 0; i < accLst.getSize(); i++)
		out << accLst.accounts[i] << "\n";
	return out;
}

/**
 * istream поток на ввод
 * @param in
 * @param accLst
 * @return in
 */
istream& operator >>(istream& in, AccountList& accLst) {
	Account acc;
	while (in >> acc)
		accLst.addUser(acc);
	return in;
}

/**
 * Оператор сравнения для AccountList
 * @param accountList
 * @return true/false
 */
bool AccountList::operator==(const AccountList& accountList) const {
    return this->accounts == accountList.accounts;
}
