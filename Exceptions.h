#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <iostream>

using namespace std;

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
