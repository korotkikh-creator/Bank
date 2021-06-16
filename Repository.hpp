#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Bank.hpp"


//класс для работы с базой данных(текстовый файл)
/**
 * класс для работы с базой данных
 */
class Repository {
    //поля
    //банк сохраненный или загруженный
    Bank bank;
    
    std::string filename;

public:
    
    Repository(const std::string &filename);

    
    Repository(const Bank &bank);

    
    /**
     * геттер для получения банка
     * @return bank
     */
    Bank &getBank();

    
    /**
     * метод сохранения банка в файл
     * @param filename
     */
    void Save(std::string filename);

    
    /**
     * удаление банка из файла
     * @param filename
     */
    void Delete(std::string filename);

    
    /**
     * обновление банка в файле
     * @param filename
     */
    void Update(std::string filename);
};

#endif
