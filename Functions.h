#include <iostream>
#include <string.h>
#include <fstream>
#include <string>

using namespace std;

void tokenizer(char* statement) {

    char* token;
    char* words[20];
    int i = 0;
    token = strtok(statement, " ,()");

    while (token != NULL) {
        words[i] = token;
        i++;
        token = strtok(NULL, " ,()");
    }



    if (strcmp(words[0], "create") == 0 && strcmp(words[1], "table") == 0) {
        cout << words[2] << endl;
        for (int k = 3; k < sizeof(words); k++) {

        }
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