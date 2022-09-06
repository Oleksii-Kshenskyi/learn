// A skeleton of a C++ single compilation unit project.
#include <iostream>

#include "lib.hxx"
#include <CLI/CLI.hpp>

std::string print(bool flag) {
    return ((flag) ? std::string("true") : std::string("false"));
}
std::string print(std::string& str) {
    return ((str.empty()) ? (std::string("<EMPTY>")) : str);
}

int main(int argc, char** argv) {
    CLI::App app { "A small videogame database application." };

    bool list_records { false };
    app.add_flag("--list,-l", list_records, "List all videogames currently in the database.");
    bool write_new_record { false };
    app.add_flag("--write,-w", write_new_record, "Write a new record into the database.")
        ->excludes("-l");

    std::string lookup_by_title {};
    app.add_option("--title,-t", lookup_by_title, "Lookup games in the database by their title.")
        ->excludes("-w")
        ->excludes("-l");
    std::string lookup_by_developer {};
    app.add_option("--developer,-d", lookup_by_developer, "Lookup games in the database by their developer studio name.")
        ->excludes("-t")
        ->excludes("-w")
        ->excludes("-l");
    std::string lookup_by_publisher {};
    app.add_option("--publisher,-p", lookup_by_publisher, "Lookup games in the database by their publisher name.")
        ->excludes("-d")
        ->excludes("-t")
        ->excludes("-w")
        ->excludes("-l");

    CLI11_PARSE(app, argc, argv);

    std::cout << "List: " << print(list_records) << ";" << std::endl;
    std::cout << "Write: " << print(write_new_record) << ";" << std::endl;
    std::cout << "lookup_by_title: " << print(lookup_by_title) << ";" << std::endl;
    std::cout << "lookup_by_developer: " << print(lookup_by_developer) << ";" << std::endl;
    std::cout << "lookup_by_publisher: " << print(lookup_by_publisher) << "." << std::endl;

    return 0;
}
