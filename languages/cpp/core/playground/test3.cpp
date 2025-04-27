#include <iostream>
#include <map>
#include <string>

int main(int argc, char **argv) {
    std::map<std::string, int> keyval = {
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
    };

    try {
        std::cout << keyval["KKEW"] << std::endl;
    } catch (std::out_of_range &e) {
        std::cout << "Key not found!" << std::endl;
    }
    std::cout << "Hello, world!" << std::endl;
    return 0;
}