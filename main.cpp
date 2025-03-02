#include "Utils.h"
#include "Table.h"
#include "Database.h"

#define COMMAND_SIZE 1024

int main() {
    Database db;
    char statement[COMMAND_SIZE];
    bool isRunning = true;

    ofstream outputFile("./Output/out");


    cout << "Enter sqlite commands:";

    while(isRunning) {
        cout << endl << ">> ";

        cin.getline(statement, COMMAND_SIZE);

        for (int i = 0; i < strlen(statement); i++) {
            statement[i] = tolower(statement[i]);
        }

        if (strstr(statement, "create table") != nullptr) {
            Database::processCreateTable(statement);
        }
        else if (strstr(statement, "insert into") != nullptr) {
            Database::processInsertInto(statement);
        }
        else if (strstr(statement, "select") != nullptr) {
            Database::processSelectFrom(statement);
        }
        else if (strstr(statement, "drop table") != nullptr) {
            Database::processDropTable(statement);
        }
        else if (strstr(statement, "display table") != nullptr) {
            Database::processDisplayTable(statement);
        }
        else if (strstr(statement, "delete from") != nullptr) {
            Database::processDeleteFrom(statement);
        }
        else if (strstr(statement, "exit") != nullptr) {
            cout << "Exiting sqlite...";
            isRunning = false;
        }
        else {
            cout << "Error: invalid command";
        }


    }

    return 0;
}

