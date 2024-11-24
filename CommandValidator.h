#pragma once

#include "Utils.h"

class CommandValidator {
public:
//CREATE TABLE table_name [IF NOT EXISTS] ((column_1_name,type,size, default_value), (column_2_name,type,size, default_value), …)
    static bool validateCreateTable(const char* command) {
        char temp[1024];
        strcpy(temp, command);

        char* token;

        token = strtok(temp, " ");
        if (!token || strcmp(token, "create") != 0) {
            cout << "Error: command must start with CREATE";
            return false;
        }

        token = strtok(NULL, " ");
        if (!token || strcmp(token, "table") != 0) {
            cout << "Error: command should have TABLE keyword, after CREATE";
            return false;
        }

        token = strtok(NULL, " ");
        if (!token) {
            return false;
        }
        char tableName[100];
        strcpy(tableName, token);


        if(strstr(temp, "if not exists") != nullptr) {
            //TODO

            //TODO if there is an existing table
        }

        char* columnDeclaration[100];
        int i = 0;
        while(token) {
            token = strtok(NULL, " (),");
            columnDeclaration[i++] = token;
            token = strtok(NULL, " (),");
            columnDeclaration[i++] = token;
            token = strtok(NULL, " (),");
            columnDeclaration[i++] = token;
            token = strtok(NULL, " (),");
            columnDeclaration[i++] = token;

            if (strcmp(token, ";") == 0) {
                break;
            }
        }


        return true;
    }
};