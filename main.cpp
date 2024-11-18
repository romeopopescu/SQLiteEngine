#include "Utils.h"
#include "Functions.h"
#include "Table.h"

#define SIZE 100

class Engine {
private:
    int liters = 0;
public:
    Engine(){}
    Engine(int l) {
        this->liters = l;
    }
};
class Car {
private:
    char* model = nullptr;
    Engine engine;
public:
    Car(const char* model, Engine engine) {
        this->model = new char[strlen(model) - 1];
        strcpy(this->model, model);
        this->engine = engine;
    }
};
int main() {
    Engine e(2);
    Car c("audi", e);

    char statement[SIZE];

    cout << "Enter sqlite commands:\n";
    cout << ">> ";
    cin.getline(statement, SIZE);

    tokenizer(statement);


    return 0;
}

