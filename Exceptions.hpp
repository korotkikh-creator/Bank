#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

/**
 * Пользователь уже ранее был зарегистрирован с таким номером
 */
class UserExistsException : std::exception{
    std::string message;

public:
    UserExistsException(std::string message) {
        this->message = message;
    }

    std::string getMessage() {
        return this->message;
    }
};

/**
 * исключение пустого списка
 */
class EmptyListException : std::exception{
    std::string message;

public:
    EmptyListException(std::string message) {
        this->message = message;
    }

    std::string getMessage() {
        return this->message;
    }
};

/**
 * выход за границы списка
 */
class IndexOfRangeException : std::exception{
    std::string message;

public:
    IndexOfRangeException(std::string message) {
        this->message = message;
    }

    std::string getMessage() {
        return this->message;
    }
};

/**
 * выход за границы списка
 */
class UserNotFoundException : std::exception{
    std::string message;

public:
    UserNotFoundException(std::string message) {
        this->message = message;
    }

    std::string getMessage() {
        return this->message;
    }
};

/**
 * файл не найден
 */
class FileNotFoundException : std::exception{
    std::string message;

public:
    FileNotFoundException(std::string message) {
        this->message = message;
    }

    std::string getMessage() {
        return this->message;
    }
};

/**
 * ошибка работы с файлом
 */
class FileErrorException : std::exception{
    std::string message;

public:
    FileErrorException(std::string message) {
        this->message = message;
    }

    std::string getMessage() {
        return this->message;
    }
};

/**
 * баланса не достаточно для перевода
 */
class SumIsBiggerThanBalance : std::exception{
    std::string message;

public:
    SumIsBiggerThanBalance(std::string message) {
        this->message = message;
    }

    std::string getMessage() {
        return this->message;
    }
};

#endif
