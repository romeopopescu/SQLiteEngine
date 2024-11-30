#pragma once
#include "Table.h"
#include "CommandValidator.h"

class Database {
private:
    char* name = nullptr;
    Table** tables = nullptr;
    int tableNo = 0;

public:
    Database() {}

    Database(const char* name) {
        this->setName(name);
    }
    void setName(const char* newName) {
        this->name = new char[sizeof(newName)];
        for (int i = 0; i < sizeof(newName); i++) {
            this->name[i] = newName[i];
        }
    }
    static bool processSelectFrom(const char* command) {
        if (CommandValidator::validateSelectFrom(command)) {
            cout << "Command is valid";

        }
        return false;
    }

    static bool processCreateTable(const char* command) {
        if (CommandValidator::validateCreateTable(command)) {
            cout << "Command is valid";
            char temp[1024];
            strcpy(temp, command);

            char* token = strtok(temp, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            Table* table = new Table(token);;
            table->printTableName();

        }
        return false;
    }



};