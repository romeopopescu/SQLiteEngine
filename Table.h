#pragma once
#include "Utils.h"
#include "Row.h"
#include "Column.h"

class Table{
private:
    char* name = nullptr;
    int noRows = 0;
    Row row;
    Column column;

public:
    Table() {

    }
    Table(const char* name, int rows) {
        setName(name);
        this->noRows = rows;
    }
    void setName(const char* newName) {
        this->name = new char[sizeof(newName)];
        for (int i = 0; i < sizeof(newName); i++) {
            this->name[i] = newName[i];
        }
    }
    void printTableName() {
        printf("%s", this->name);
    }
};