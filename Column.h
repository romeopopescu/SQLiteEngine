#pragma once
#include "Utils.h"

enum Type{ INTEGER, FLOAT, TEXT };

class Column {
private:
    char* name = nullptr;
    Type type = Type::TEXT;
    int size = 0;
    //default value;

public:
    Column() {}

    Column(const char* name, Type type, int size) {
        this->setName(name);
        this->setType(type);
        this->setSize(size);
    }
    void setSize(int newSize) {
        if (newSize < 0) {
            throw "Invalid column size";
        }
        this->size = newSize;
    }
    void setName(const char* newName) {
        if (this->name != nullptr) {
            delete[] this->name;
        }
        this->name = new char[strlen(newName) - 1];
        strcpy(this->name, newName);
    }
    void setType(Type newType) {
        this->type = newType;
    }
};