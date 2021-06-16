#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Bank.hpp"


//класс для работы с базой данных(текстовый файл)
class Repository {
    //поля
    //банк сохраненный или загруженный
    Bank bank;
    //имя файла откуда загрузка или куда
    std::string filename;

public:
    //конструктор принимает на вход имя файла откуда будет произведена загрузка
    Repository(const std::string &filename);

    //конструктор принимает на вход банк , который может быть сохранен в файл
    Repository(const Bank &bank);

    //геттер для получения банка
    Bank &getBank();

    //метод сохранения банка в файл
    void Save(std::string filename);

    //удаление банка из файла
    void Delete(std::string filename);

    //обновление банка в файле
    void Update(std::string filename);
};

#endif
