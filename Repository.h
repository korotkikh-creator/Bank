#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Bank.h"

using namespace std;

//класс для работы с базой данных(текстовый файл)
class Repository {
    //поля
    //банк сохраненный или загруженный
	Bank bank;
	//имя файла откуда загрузка или куда
	string filename;

public:
    //конструктор принимает на вход имя файла откуда будет произведена загрузка
	Repository(const string& filename);
    //конструктор принимает на вход банк , который может быть сохранен в файл
	Repository(const Bank& bank);
	//геттер для получения банка
	Bank& getBank();
	//метод сохранения банка в файл
	void Save(string filename);
	//удаление банка из файла
	void Delete(string filename);
	//обновление банка в файле
	void Update(string filename);
};

#endif
