#include "Repository.hpp"
#include "Exceptions.hpp"
#include <fstream>
using namespace std;

/**
 * констурктор принимает на вход имя файла и производит загрузуку банка из файла
 * @param filename
 */
Repository::Repository(const string &filename) {
    
    ifstream ifs(filename);
    
    if (!ifs)
        
        throw FileNotFoundException("The file wasn't found");
    
    this->filename = filename;
    
    
    ifs >> this->bank;
    
    ifs.close();
}


/**
 * конструктор инициализирует поле банк класса
 * @param bank
 */
Repository::Repository(const Bank &bank) {
    this->bank = bank;
}


/**
 * геттер возвращает ссылку на банк
 * @return bank
 */
Bank &Repository::getBank() {
    return this->bank;
}



/**
 * метод сохранения репозитория в файл
 * @param filename
 */
void Repository::Save(string filename = "") {
    
    if (filename == "")
        filename = this->filename;
    
    this->filename = filename;
    
    ofstream of(this->filename);
    
    if (!of)
        throw FileErrorException("File error");
   
    of << this->bank << endl;
    of.close();
}

/**
 * метод удаления банка из файла
 * @param filename
 */
void Repository::Delete(string filename = "") {
    if (filename == "")
        filename = this->filename;
    this->filename = filename;
    
    ofstream of(this->filename);
    if (!of)
        throw FileErrorException("File error");
   
    of.close();
}

/**
 * метод обновления банка
 * @param filename
 */
void Repository::Update(string filename = "") {
    Save(filename);
}
