#pragma once
#include "Utils.h"
#include "Table.h"

void tokenizer(char* statement) {

    char* token;
    char* words[20];
    int index = 0;
    token = strtok(statement, " ,()");

    while (token != NULL) {
        for (int i = 0; i < strlen(token); i++) {
            token[i] = tolower(token[i]);
        }
        words[index] = token;
        index++;
        token = strtok(NULL, " ,()");
    }

    if (strcmp(words[0], "create") == 0 && strcmp(words[1], "table") == 0) {
        //TO DO
        Table table;
        table.createTable(words);
        table.printTableName();
        table.printTable();
    }
    else if (strcmp(words[0], "insert") == 0 && strcmp(words[1], "into") == 0) {

    }
    else if (strcmp(words[0], "select") == 0) {
        //TO DO
    }
    else if (strcmp(words[0], "drop") == 0 && strcmp(words[1], "table") == 0) {
        //TO DO
    }
    else if (strcmp(words[0], "display") == 0) {
        //TO DO
    }
    else if (strcmp(words[0], "create") == 0 && strcmp(words[1], "index") == 0) {
        //TO DO
    }
    else if (strcmp(words[0], "drop") == 0 && strcmp(words[1], "index") == 0) {
        //TO DO
    }
    // TO DO else ifs for UPDATE DELETE INSERT INTO....

}
