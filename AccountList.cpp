#include "AccountList.h" 

//Метод добавления нового аккаунта в список всех аккаунтов
void AccountList::addUser(const Account& account) {
    //Проверяет нет ли аккаунта с таким же номером уже в списке всех аккаунтов
    //если не равен nullptr то генерируем ошибку что такой аккаунт уще есть
	if (searchByNumber(account.getNumber()) != nullptr)
		throw UserExistsException("The user with this number is already added");
	//если ошибки нет то добавляет аккаунт в список
	this->accounts.push_back(account);
}

//Метод поиска аккаунта по его номеру
//возвращает указатель(адрес) аккаунта
Account* AccountList::searchByNumber(string number) {
    //циклом проходим по всем аккаунтам из списка и
    //если находим аккаунт с таким же номером как
    //в аргументах то возвращаем ссылку(адрес) этого аккаунта
	for (int i = 0; i < this->accounts.size(); i++) {
		if (this->accounts[i].getNumber() == number)
			return &this->accounts[i]; // & означает что возвращаем адрес
	}
	//возвращается ключевое слово nullptr если такой аккаунт не найден в списке
	return nullptr;
}

//Метод удаления аккаунта из списка всех аккаунтов
bool AccountList::deleteUser(const Account& account) {
    //Если список пуст то нечего удалять,
    //генерируем ошибку что список пуст
	if (this->accounts.size() == 0)
		throw EmptyListException("The list is empty");
	//находит аккаунт в списке всех аккаунтов
	//делается функцией find из стандартной библиотеки
	//возвращает итератор либо на конец списка если аккаунт не найден
	//либо на тот аккаунт который нашли
	vector<Account>::iterator it = find(this->accounts.begin(), this->accounts.end(), account);
	//если вернулся итератор на конец то не нашли аккаунт возвращаем false
	if (it == this->accounts.end())
		return false;
	//если нашли аккаунт то удаляем его из списка
	this->accounts.erase(it);
	//возвращаем true
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

//Перегрузка оператора индексации
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