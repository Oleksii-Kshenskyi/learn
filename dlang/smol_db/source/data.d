module data;

import std.stdio;
import d2sqlite3;
import std.typecons : Nullable;

Database init() {
    auto db = Database("database.db");
    db.run("
        CREATE TABLE IF NOT EXISTS videogame (
          title  TEXT NOT NULL,
          year INTEGER,
          developer TEXT,
          publisher TEXT,
          genre TEXT
        )");
    return db;
}

Statement insert_statement(Database db) {
    return db.prepare("INSERT INTO videogame
                      VALUES (:title, :year, :developer, :publisher, :genre)");
}



void select_and_print(Database db) {
    auto count = db.execute("SELECT count(*) FROM videogame")
                   .oneValue!long;
    writeln("Videogames in the database: ", count);

    auto result = db.execute("SELECT * FROM videogame");
    writeln("========VIDEOGAMES=========="); writeln();
    foreach(record; result) {
        auto id = record.peek!long(0);
        writeln("Row ID: ", id);
        writeln("Game Title: ", record["title"].as!string);
        writeln("Released In: ", record["year"].as!int);
        writeln("Developer Studio: ", record["developer"].as!string);
        writeln("Publisher: ", record["publisher"].as!string);
        writeln("Genre: ", record["genre"].as!string); writeln();
    }
    writeln("===========END=============");
}

void insert_new_game(Database db) {}
void select_by_name(Database db, string* name) {}
void select_by_developer(Database db, string* developer) {}
void select_by_publisher(Database db, string* publisher) {}