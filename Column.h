enum Type{ INTEGER, FLOAT, TEXT };

class Column {
private:
    char* name = nullptr;
    Type type = Type::TEXT;

public:
    Column() {}

    Column(const char* name, Type type) {
        this->setName(name);
        this->setType(type);
    }
    void setName(const char* newName) {
        if (this->name != nullptr) {
            delete this->name;
        }
        this->name = new char[strlen(newName) - 1];
        strcpy(this->name, newName);
    }
    void setType(Type newType) {
        this->type = newType;
    }

};