#include "Repository.h"
#include "Exceptions.h"
#include <fstream>

//конструктор принимает на вход имя файла и производит загрузку банка из файла
Repository::Repository(const string& filename) {
    //открывается поток на чтение из файла по его пути(имени)
	ifstream ifs(filename);
	//если файл не удалось открыть (например он отсутствует)
	if (!ifs)
	    //бросается исключение
		throw FileNotFoundException("The file wasn't found");
	//инициализация поля аргументом
	this->filename = filename;
	//чтение из потока банка и запись его в поле
	//>> сработает из класса Bank
	ifs >> this->bank;
	//закрываем поток
	ifs.close();
}

//конструктор инициализирует поле банк класса
Repository::Repository(const Bank& bank) {
	this->bank = bank;
}

//геттер возвращает ссылку на банк
Bank& Repository::getBank() {
	return this->bank;
}

//метод сохранения принимает на вход имя файла а может не принимать
//но только в имя файла запишется по умолчанию пустая строка ""
void Repository::Save(string filename = "") {
	//если мы ничего не передали в этот метод то он берет имя файла из поля класса
    if (filename == "")
		filename = this->filename;
    //если же мы передали какой-то аргумент то он запишется в поле класса
	this->filename = filename;
	//открытие пока на вывод по имени(пути) файла
	ofstream of(this->filename);
	//если файл отстутствует то он автоматически сам создается программой
	//но если в переданном пути невозможно
	//создать новый файл то бросается исключение
	if (!of)
		throw FileErrorException("File error");
	//вывод банка в поток
	of << this->bank << endl;
	of.close();
}

//удаление банка из файла
//с аргументом аналогично выше
void Repository::Delete(string filename = "") {
	if (filename == "")
		filename = this->filename;
	this->filename = filename;
	//открываем поток на вывод в файл и автоматически
	//если тмакой файл уже есть то все внутри удаляется,
	//информация очищается файла
	ofstream of(this->filename);
	if (!of)
		throw FileErrorException("File error");
	//просто закрываем поток
	of.close();
}

//обновление банка это значит заново сохранить
//в имеющийся файл новой информации
void Repository::Update(string filename = "") {
	Save(filename);
}