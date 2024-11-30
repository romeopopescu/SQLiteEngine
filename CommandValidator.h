#pragma once

#include "Utils.h"

class CommandValidator {
public:

    static bool validateInsertInto(const char* command) {
        return true;
    }
//    SELECT (at_least_one_column, ...) | ALL FROM table_name
    static bool validateSelectFrom(const char* command) {
        char temp[1024];
        strcpy(temp, command);

        char* token;

        token = strtok(temp, " ");
        if (!token || strcmp(token, "select") != 0) {
            cout << "Error: command must start with SELECT";
            return false;
        }

        token = strtok(NULL, " ,");
        int w = 0;
        while (strcmp(token, "from") != 0) {
            if (!token) {
//                TODO create verifyIfColumnExists
                cout << "Error: missing column or *";
                return false;
            }
            if (w > 5) {
                cout << "Error: too many columns or missing FROM";
            }
            w++;
            token = strtok(NULL, " ,");
        }
        if (w == 0) {
            cout << "Error: missing column name or *";
            return false;
        }

        token = strtok(NULL, " ,");
        char * tableName = token;
        if (!tableName) {
            cout << "Error: missing table name";
            return false;
        }
        if (tableName[strlen(tableName) - 1] != ';'){
            token = strtok(NULL, " ");
            if (!token || strcmp(token, ";") != 0) {
                cout << "Error: missing semi colon ;";
                return false;
            }
        }

        return true;
    }
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
            cout << "Error: Missing name";
            return false;
        }
        char tableName[100];
        strcpy(tableName, token);


        if(strstr(temp, "if not exists") != nullptr) {
            //TODO
            if(!isValidTableName(tableName)) {
                return false;
            }
            //TODO if there is an existing table
        }

        char* columnDeclaration[100];
        int i = 0;

        //token is column name
        token = strtok(NULL, " (),");
        if (!token) return false;
        while(token) {

            token = strtok(NULL, " (),");
            if (!token) return false;
            //token is column type
            if(strcmp(token, "text") != 0 && strcmp(token, "integer") != 0 && strcmp(token, "float") != 0) {
                cout << "Error: Invalid column type";
                return false;
            }

            token = strtok(NULL, " (),");
            //token is column size
            if (!token) return false;
            for (i = 0; i < strlen(token); i++) {
                if (!isdigit(token[i])) {
                    cout << "Error: Size is not a number";
                    return false;
                }
            }

            token = strtok(NULL, " (),");
            if (!token) return false;
            //token is column initial value

            token = strtok(NULL, " (),");
            if (strcmp(token, ";") == 0) {
                break;
            }
        }


        return true;
    }

private:
    static bool isValidTableName(const char* name) {

        return true;
    }
    static bool isValidColumnName(const char* name) {


        return true;
    }
};