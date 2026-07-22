#include <iostream>



[[nodiscard]] int keke() {
    return 42;
}

enum class Types {
    TypeOne = 1,
    TypeTwo = 2,
};

int typer(Types t) {
    switch (t) {
        case Types::TypeOne:
            return 1;
        case Types::TypeTwo:
            return 2;
        default:
            return -1;
    }
}

int main() {
    std::cout << "Trying to use keke() without using its return value." << std::endl;
    int kek = keke();
    std::cout << "keke() returned => " << kek << std::endl;


    std::cout << "Typer returned => " << typer(Types { -42 }) << std::endl;
    return 0;
}