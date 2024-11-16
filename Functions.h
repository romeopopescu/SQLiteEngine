#include "Utils.h"
#include "Column.h"

void createTable(char* words[20]);

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
        createTable(words);
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
    //la insert into pune in Row class
    //create table se foloseste de Column si table??


}
//CREATE TABLE table_name (column1 datatype, column2 datatype);
void createTable(char* words[20]) {
    int i = 3;
    while(words[i + 1]) {
        if (strcmp(words[i+1], "text") == 0) {
            Column(words[i], words[i+1]);
        }
        else if (strcmp(words[i + 1], "integer")) {
            Column(words[i], words[i+1]);
        }
    }
}