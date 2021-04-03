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

#endif
