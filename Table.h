#pragma once
#include "Utils.h"
#include "Row.h"
#include "Column.h"

class Table{
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
        this->name = new char[sizeof(newName)];
        for (int i = 0; i < sizeof(newName); i++) {
            this->name[i] = newName[i];
        }
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

//CREATE TABLE table_name (column1 datatype, column2 datatype);
//    void createTable(char* words[20]) {
//        this->setName(words[2]);
//        int i = 3;
//        while(words[i + 1]) {
//            if (strcmp(words[i+1], "text") == 0) {
//                this->columns[this->columnCount] = new Column(words[i], TEXT, 1);
//                this->columnCount++;
//            }
//            else if (strcmp(words[i + 1], "integer") == 0) {
//                this->columns[this->columnCount] = new Column(words[i], INTEGER, 1);
//                this->columnCount++;
//            }
//            else if (strcmp(words[i + 1], "float") == 0) {
//                this->columns[this->columnCount] = new Column(words[i], FLOAT, 1);
//                this->columnCount++;
//            }
//            i += 2;
//            if (strcmp(words[i], ";") == 0) return;
//        }
//    }
    void addRow(char* words[20]) {

    }

};