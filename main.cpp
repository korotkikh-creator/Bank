#include "Account.h"
#include "AccountList.h"
#include "Bank.h"
#include "Repository.h"

//функция создания аккаунта
void createAccount(Bank& bank) {
	string number;
	//нельзя добавлять новый аккаунт с таким же номером телефона
	//если это так то бросается исключение
	do {
		cout << "Enter your phone number: ";
		cin >> number;
		if (bank.searchByNumber(number) != nullptr)
			throw UserExistsException("The user with this number already exists");
		if (number.size() != 11)
			cout << "The phone number must contain exactly 11 characters" << endl;
	} while (number.size() != 11);

	cout << "Please enter your last name: ";
	string surname;
	cin >> surname;

	cout << "Enter your name: ";
	string name;
	cin >> name;

	cout << "Enter middle name: ";
	string middleName;
	cin >> middleName;

	cout << "Enter a balance: ";
	double balance;
	cin >> balance;
	//вызов метода добавления аккаунта в банк
	bank.addAccount(Account(number, surname, name, middleName, balance));
}

int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Do you want to upload a file or work with a new bank?" << endl;
	cout << "Select the answer option you need by entering a number:\n1) Load bank from file\n2) Create a new bank" << endl;
	int n;
	//запрос у пользователя, загрузить из файла или создать новый
	cin >> n;
	Bank bank;
	string filename;
	//если введено 1 то загрузка из файла
	if (n == 1) {
	    //пока пользователь не введет верно имя файла
	    //программа бесконечно будет запрашивать у него это имя
		while (true) {
			//брошенное исключение FileNotFoundException обрабатывается в блоке catch
			//в блоке try пишется код, который может выбросить данную ошибку
		    try {
			    //ввод имени файла
				cout << "Enter the name of the file from which you want to load the bank" << endl;
				cin >> filename;
				//создание объекта репозитория, передача ему имени файла и получение банка из репозитория
				bank = Repository(filename).getBank();
				break;
			}
			catch (FileNotFoundException e) {
			    //в переменную е запишется информация об ошибке
			    //е - объект класса FileNotFoundException
			    //геттером производим получение сообщения об ошибке
				cout << e.getMessage() << endl;
			}
		}
	}
	else if (n == 2) {
	    //если пользователь выбрал создание нового банка
	    //то создается пустой объект банка и заполняется
	    //аккаунтами с клавиатуры
		bank = Bank();
		cout << "How many accounts do you want to add?" << endl;
		int count;
		cin >> count;
		//если внутри цикла будут какие-то ошибки то пока
		//нужное количество аккаунтов не будет введено
		//программа будет запрашивать новый аккаунт
		for (int i = 0; i < count; ) {
			cout << "Create an account number " << (i + 1) << endl;
			try {
			    //вызов функции создания аккаунта
				createAccount(bank);
				i++;
			}
			catch (UserExistsException u) {
				cout << u.getMessage() << endl;
			}
			cout << "\n";
		}
	}
	else {
		cout << "Number entered incorrectly, please try again";
        return 1;
	}

	//банк либо создан как новый либо загружен из файла
	//далее можно выполнять с ним операции
	while (true)
	{
		cout << "Select the operation you need from the list: " << endl;
		cout << "1) Creating and adding a new account" << endl;
		cout << "2) One-bank transfer" << endl;
		cout << "3) Removing an account from the bank" << endl;
		cout << "4) Saving a bank to another file" << endl;
		cout << "5) Updating the bank in the source file" << endl;
		cout << "6) Display the bank (list of accounts) on the screen" << endl;
		cout << "7) Remove bank from source file" << endl;
		cout << "8) Log out" << endl;
		int m;
		cin >> m;
		//выбор в зависимости от ввода действий с банком
		switch (m) {
		case 1:
			try {
				createAccount(bank);
			}
			catch (UserExistsException u) {
				cout << u.getMessage() << endl;
			}
			break;
		case 2: {
		    //ввод номеров телефонов откуда перевод и кому перевод, суммы
			cout << "Enter the phone number of the account from which the transfer is made: ";
			string senderNumber;
			cin >> senderNumber;

			cout << "Enter the phone number of the account to which the amount will be transferred: ";
			string receiveNumber;
			cin >> receiveNumber;

			cout << "Enter the amount you want to transfer: ";
			double sum;
			cin >> sum;

            //если аккаунты не найдены то сгенерируются и обработаются исключения
            //либо пользователи не найдены, либо суммы для перевода недостаточно
            try {
                bank.transaction(senderNumber, receiveNumber, sum);
            }
            catch (UserNotFoundException us) {
                cout << us.getMessage() << endl;
            }
            catch (SumIsBiggerThanBalance s) {
                cout << s.getMessage() << endl;
            }
			break;
		}
		case 3: {
			cout << "Enter the phone number of the account you want to delete: ";
			string delNumber;
			cin >> delNumber;
			//поиск аккаунта по номеру телефона
			Account* delAcc = bank.searchByNumber(delNumber);
			//если не найден то вывод сообщения
			if (delAcc == nullptr) {
				cout << "Account is not found!" << endl;
			}
			else
			    //если найден то удаление его
			    bank.deleteAccount(*delAcc);
			break;
		}
		case 4: {
			cout << "Enter the name of the file you want to save the bank to: ";
			//ввод имени файла куда сохранить банк
			string newFilename;
			cin >> newFilename;
			Repository repSave(bank);
			try {
			    //сохранение банка в новый файл
				repSave.Save(newFilename);
			}
			catch (FileErrorException f) {
				cout << f.getMessage() << endl;
			}
			break;
		}
		case 5: {
		    //обновление банка в файле
		    //если банк еще не был ранее загружен то выводим ошибку
			if (filename == "")
				cout << "Firstly, save the bank to a file!" << endl;
			else {
			    //если банк был загружен ранее из какого-то файла то
			    //производим обновление банка в этом файле
				Repository repUpdate(bank);
				try {
					repUpdate.Update(filename);
				} catch (FileErrorException f) {
					cout << f.getMessage() << endl;
				}
			}
			break;
		}
		case 6:
		    //вывод банка на экран
		    //вызывается << для банка
			cout << "Bank: " << endl;
			cout << bank << endl;
			break;
		case 7: {
		    //удаление банка из файла
		    //если банк еще не был загружен то выводим ошибку
			if (filename == "")
				cout << "Unable to delete a bank because there is no place to delete it from!" << endl;
			else {
			    //если банк ранее был загружен из файла
			    //то производим удаление банка в этом файле
			    //при этом сам файл не удаляется
			    //а удаляется только информация о банке в этом файле
			    //файл очищается
				Repository repDelete(bank);
				try {
					repDelete.Delete(filename);
				} catch (FileErrorException f) {
					cout << f.getMessage() << endl;
				}
			}
			break;
		}
		case 8:
		    //выход из программы
		    //выход из цикла
			return 0;
		default:
		    //обработка неизвестной команды
			cout << "Operation number entered incorrectly, please, try again" << endl;
			break;
		}
	}
	return 0;
}