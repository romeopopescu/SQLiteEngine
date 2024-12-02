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
            char temp[1024];
            strcpy(temp, command);


            char* token = strtok(temp, " ");
            token = strtok(NULL, " ");
            token = strtok(NULL, " ");
            Table* table = new Table(token);
//            create table names ((column1, integer, 10, 12),(column2, float, 10, 13.34));
//            //creating columns
            // Move inside the column definitions
            token = strtok(NULL, "("); // Skip first '('
            while (token) {
                char* columnName = strtok(token, ", "); // Column name
                if (!columnName) break;

                char* typeName = strtok(NULL, ", "); // Column type
                if (!typeName) {
                    std::cerr << "Error: Missing type for column " << columnName << ".\n";
                    return false;
                }

                char* sizeStr = strtok(NULL, ", "); // Column size as string
                if (!sizeStr) {
                    std::cerr << "Error: Missing size for column " << columnName << ".\n";
                    return false;
                }
                int size = atoi(sizeStr); // Convert size to int

                char* defaultValue = strtok(NULL, ",) "); // Default value
                if (!defaultValue) {
                    std::cerr << "Error: Missing default value for column " << columnName << ".\n";
                    return false;
                }

                // Add the column to the table
                try {
                    table->addColumn(columnName, typeName, size, defaultValue);
                } catch (const std::exception& e) {
                    std::cerr << "Error adding column: " << e.what() << "\n";
                    return false;
                }
                // Move to the next column
                token = strtok(NULL, "(, "); // Go to the next column group
            }

            return true;
        }

        return false;
    }

};