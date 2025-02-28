#pragma once
#include "Utils.h"
#include "Row.h"
#include "Column.h"

class Table {
private:
    char* name = nullptr;
    Row** rows = new Row*[20];
    int rowCount = 0;
    Column** columns = new Column*[20];
    int columnCount = 0;

public:
    Table() {

    }
    Table(const char* name) {
        this->setName(name);
        this->columns = nullptr;
        this->rows = nullptr;
    }
    void setName(const char* newName) {
        delete[] this->name;
        this->name = new char[sizeof(newName)];
        strcpy(this->name, newName);

    }
    void printTableName() {
        printf("%s", this->name);
    }
    void printTable() {
        cout << this->name << endl;
        for (int i = 0; i < this->columnCount; i++) {
            this->columns[i]->printColumn();
        }
    }
//CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), …)
    void addColumn(const char* nameColumn, const char* type, int size, const char* value) {
        cout << endl << "Entered add column method";
        if (strcmp(type, "text") == 0) {
            this->columns[this->columnCount] = new Column(nameColumn, TEXT, size, value);
            this->columnCount++;
        } else if (strcmp(type, "integer") == 0) {
            this->columns[this->columnCount] = new Column(nameColumn, INTEGER, size, value);
            this->columnCount++;
        } else if (strcmp(type, "float") == 0) {
            this->columns[this->columnCount] = new Column(nameColumn, FLOAT, size, value);
            this->columnCount++;
        }
    }
//    void addColumn(const Column& column);
//    void addRow(const Row& row);
//    Row* getRow(int index);

    void addRow(const char* words[20]) {
        cout << endl << "add row method";
        if (this->rowCount < 20) {
            rows[rowCount++] = new Row(words);
        }
    }

    ~Table() {
        delete[] name;
        for (int i = 0; i < rowCount; i++) {
            delete rows[i];
        }
        delete[] rows;
        for (int i = 0; i < columnCount; i++) {
            delete columns[i];
        }
        delete[] columns;
    }

};