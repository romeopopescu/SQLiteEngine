#pragma once

#include "Utils.h"

class CommandValidator {
private:
    char* command;
public:
    CommandValidator(const char* command) {
        this->command = new char[strlen(command) - 1];
        strcpy(this->command, command);
    }
    void validateCreateTable() {

    }
};