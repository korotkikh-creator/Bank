#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

using namespace std;

//классы исключений

//Пользователь уже ранее был зарегистрирован с таким номером
class UserExistsException {
    string message;

public:
    UserExistsException(string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

//исключение пустого списка
class EmptyListException {
    string message;

public:
    EmptyListException(string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

//выход за границы списка
class IndexOfRangeException {
    string message;

public:
    IndexOfRangeException(string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

//пользователь не найден
class UserNotFoundException {
    string message;

public:
    UserNotFoundException(string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

//файл не найден
class FileNotFoundException {
    string message;

public:
    FileNotFoundException (string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

//ошибка работы с файлом
class FileErrorException {
    string message;

public:
    FileErrorException(string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

//баланса не достаточно для перевода
class SumIsBiggerThanBalance {
    string message;

public:
    SumIsBiggerThanBalance(string message) {
        this->message = message;
    }

    string getMessage() {
        return this->message;
    }
};

#endif
