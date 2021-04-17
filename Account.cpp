#include "Account.h"

//реализация конструктора по умолчанию
Account::Account() {
    //обнуляем баланс чтобы компилятор не записал мусор
	this->balance = 0;
	//остальные поля обнуляет компилятор сам
}

//реализация конструктора с параметрами
//Принимаем на вход аргументы(в круглых скобках)
//и присваиваем эти аргументы полям,
//то есть их инициализируем(заполняем)
Account::Account(string number, string surname, string name, string middleName, double balance) {
	this->number = number;
	this->surname = surname;
	this->name = name;
	this->middleName = middleName;
	this->balance = balance;
}

//Реализация метода увеличения баланса на заданную величину в аргументах
void Account::increaseBalance(double increase) {
    //увеличиваем баланс на то значение которое передано в скобках
	this->balance += increase;
}

//Реализация метода уменьшения баланса на заданную величину в аргументах
void Account::decreaseBalance(double decrease) {
	this->balance -= decrease;
}

//Реализация геттера
string Account::getNumber() const {
    //возвращает значение поля
	return this->number;
}

//Реализация сеттера
void Account::setNumber(string number) {
    //аргумент присваиваем в поле
    //меняем значение поля заданной величиной
	this->number = number;
}

//Реализация метода перевода денег
void Account::transaction(Account& account, double sum) {
	//у текущего аккаунта уменьшаем баланс
    this->decreaseBalance(sum);
    //а у принимающего аккаунта увеличиваем баланс
	account.increaseBalance(sum);
}

//Реализация оператора сравнения на равенство
//на вход в аргументах принимает второй объект
//и возвращает true если текущий объект
//по всем полям совпадает со вторым
bool Account::operator==(const Account& account) {
	return this->number == account.number && this->surname == account.surname && this->name == account.name
		&& this->middleName == account.middleName && this->balance == account.balance;
}

double Account::getBalance() const {
    return this->balance;
}

void Account::setBalance(double balance) {
    this->balance = balance;
}

//реализация оператора вывода
//на вход принимает поток куда вывести и аккаунт,
//который выводится в поток
ostream& operator <<(ostream& os, const Account& account) {
	return os << account.number << " " << account.surname << " " << account.name <<  " " << account.middleName << " " << account.balance;
}

//реализация оператора ввода
//на вход принимает поток откуда вводится аккаунт,
istream& operator >>(istream& in, Account& account) {
	return in >> account.number >> account.surname >> account.name >> account.middleName >> account.balance;
}