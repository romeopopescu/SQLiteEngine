#pragma once
#include "Utils.h"

enum Type{ INTEGER, FLOAT, TEXT };

class Column {
private:
    char* name = nullptr;
    Type type = Type::TEXT;
    int size = 0;
    //default value;
    char* textValue;
    int integerValue;
    float floatValue;

public:
    Column() {}

    Column(const char* name) {
        this->setName(name);
    }

    Column(const char* name, Type type, int size, const char* defVal) {
        this->setName(name);
        this->setType(type);
        this->setSize(size);
        this->setDefaultValue(defVal);
    }
    void setDefaultValue(const char* value) {
        if (this->type == INTEGER) {
            this->integerValue = atoi(value);
        }
        else if (this->type == FLOAT) {
            this->floatValue = atof(value);
        }
        else if (this->type == TEXT) {
            this->textValue = new char[strlen(value)];
            strcpy(this->textValue, value);
        }
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
    void printColumn() {
        cout << this->name << " | ";
    }
    ~Column(){
        delete[] this->name;
        delete[] this->textValue;
    }
};