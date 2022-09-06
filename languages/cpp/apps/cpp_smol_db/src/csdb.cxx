// A skeleton of a C++ single compilation unit project.
#include <iostream>

#include "lib.hxx"
#include "database.hxx"
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

    Database db;
    if(list_records) db.list_records();
    else if(write_new_record) db.write_new_record();
    else if(!lookup_by_title.empty()) db.lookup_by_title(lookup_by_title);
    else if(!lookup_by_developer.empty()) db.lookup_by_developer(lookup_by_developer);
    else if(!lookup_by_publisher.empty()) db.lookup_by_publisher(lookup_by_publisher);
    else {
        std::cout << "ERROR: it's required to specify exactly one of the five parameters so the program has something to do." << std::endl;
        std::exit(-1);
    }

    return 0;
}
