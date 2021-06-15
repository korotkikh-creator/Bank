#include "AccountList.h" 

void AccountList::addUser(const Account& account) { //метод добавления нового аккаунта в список всех аккаунтов
	if (searchByNumber(account.getNumber()) != nullptr) //проверка на существование аккаунта
		throw UserExistsException("The user with this number is already added");
	this->accounts.push_back(account);
}

Account* AccountList::searchByNumber(string number) { //метод поиска аккаунта по номеру
	for (int i = 0; i < this->accounts.size(); i++) {
		if (this->accounts[i].getNumber() == number)
			return &this->accounts[i]; //возвращает указатель на аккаунт
	}
	return nullptr;
}

//Метод удаления аккаунта из списка всех аккаунтов
bool AccountList::deleteUser(const Account& account) {
	if (this->accounts.size() == 0)
		throw EmptyListException("The list is empty");
	vector<Account>::iterator it = find(this->accounts.begin(), this->accounts.end(), account);
	if (it == this->accounts.end())
		return false;
	//если нашли аккаунт то удаляем его из списка
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

//на вход принимает индекс и возвращает
//ссылку на аккаунт который находится по данному индексу
Account& AccountList::operator[] (int index) {
    //проверка на то чтобы индекс не выходил за пределы списка
	if (index < 0 || index >= this->accounts.size())
		throw IndexOfRangeException("Wrong index");
	//возврат ссылки на аккаунт из списка аккаунтов по индексу
	return this->accounts[index];
}

bool AccountList::exists(const Account& account) {
    //циклом проходим по списку всех аккаунтов и возвращаем true
    //если данный аккаунт найден в списке
	for (int i = 0; i < this->accounts.size(); i++) {
		if (this->accounts[i] == account)
			return true;
	}
	//если в списке не нашли такого аккаунта то возвращаем false
	return false;
}

int AccountList::getSize() const {
    //если количество равно 0 то бросается исключение EmptyListException
	if (this->accounts.size() == 0)
		throw EmptyListException("The list is empty");
	//если не равно 0 то возвращается размер
	return this->accounts.size();
}

//ostream поток на вывод
ostream& operator <<(ostream& out, const AccountList& accLst) {
    //выводим все аккаунты каждое с новой строки
	for (int i = 0; i < accLst.getSize(); i++)
		out << accLst.accounts[i] << "\n";
	return out;
}

//istream поток на ввод
istream& operator >>(istream& in, AccountList& accLst) {
    //вводим акаунты и добавляем их в список пока не конец потока
	Account acc;
	while (in >> acc)
		accLst.addUser(acc);
	return in;
}
