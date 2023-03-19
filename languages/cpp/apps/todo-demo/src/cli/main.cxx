#include <string>
#include <iostream>
#include <vector>

#include "lib/test.hxx"

// TODO: Should read a bunch of notes from a file specified in command line

// TODO: Should write a new note into the file

int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);
    std::cout << "[";
    for(auto& item: args) {
        std::cout << "'" << item << "' ";
    }
    std::cout << "]" << std::endl;
    return 0;
}