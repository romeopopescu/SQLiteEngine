enum type{ INTEGER, FLOAT, TEXT };

class Column {
private:
    char* name = nullptr;
    char* type = nullptr;
public:
    Column() {}

    Column(const char* name, const char* type) {

    }
    void setName(const char* newName) {
        this->name = new char[strlen(newName) - 1];
        strcpy(this->name, newName);
    }

};