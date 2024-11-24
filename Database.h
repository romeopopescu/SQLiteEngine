#pragma once
#include "Table.h"
#include "CommandValidator.h"

class Database {
private:
    char* name = nullptr;
    Table** tables = nullptr;

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

    static bool processCreateTable(const char* command) {
        if (CommandValidator::validateCreateTable(command)) {
            return false;
        }
        return true;
    }



};