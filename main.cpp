#include "Utils.h"
#include "Functions.h"
#include "Table.h"

#define SIZE 100
int main() {

    char statement[SIZE];

    cout << "Enter sqlite commands:\n";
    cout << ">> ";
    cin.getline(statement, SIZE);
    cout << statement << endl;

    tokenizer(statement);



    return 0;
}
