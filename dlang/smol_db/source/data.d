module data;

import std.stdio;
import std.typecons;
import std.conv;
import std.string;
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
        writeln("Game Title: ", record["title"].as!string);
        writeln("Released In: ", record["year"].as!int);
        writeln("Developer Studio: ", record["developer"].as!string);
        writeln("Publisher: ", record["publisher"].as!string);
        writeln("Genre: ", record["genre"].as!string); writeln();
    }
    writeln("===========END=============");
}

void insert_new_game(Database db) {
    writeln("Please tell me some info about a videogame...");
    write("Game Title? => "); auto title = readln.strip;
    write("Year the game was released in? => "); ulong year = readln.strip.to!ulong;
    write("Studio that developed the game? => "); string dev = readln.strip;
    write("Game's publisher? => "); string pub = readln.strip;
    write("Game's genre? => "); string genre = readln.strip;

    insert_statement(db).inject(title, year, dev, pub, genre);
}

void select_by_name(Database db, string* title) {
    writeln("Games in the database that contain '", *title, "' in the title:");
    auto count = db.execute("SELECT count(*) FROM videogame WHERE title LIKE '%" ~ *title ~ "%'").oneValue!ulong;
    writeln("Games found: ", count);
    auto result = db.execute("SELECT * FROM videogame WHERE title LIKE '%" ~ *title ~ "%'");
    writeln("========SEARCH BY TITLE=========="); writeln();
    foreach(record; result) {
        writeln("Game Title: ", record["title"].as!string);
        writeln("Released In: ", record["year"].as!int);
        writeln("Developer Studio: ", record["developer"].as!string);
        writeln("Publisher: ", record["publisher"].as!string);
        writeln("Genre: ", record["genre"].as!string); writeln();
    }
    writeln("==============END===============");
}

void select_by_developer(Database db, string* developer) {
    writeln("Games in the database that contain '", *developer, "' in the developer name:");
    auto count = db.execute("SELECT count(*) FROM videogame WHERE developer LIKE '%" ~ *developer ~ "%'").oneValue!ulong;
    writeln("Games found: ", count);
    auto result = db.execute("SELECT * FROM videogame WHERE developer LIKE '%" ~ *developer ~ "%'");
    writeln("========SEARCH BY DEV NAME=========="); writeln();
    foreach(record; result) {
        writeln("Game Title: ", record["title"].as!string);
        writeln("Released In: ", record["year"].as!int);
        writeln("Developer Studio: ", record["developer"].as!string);
        writeln("Publisher: ", record["publisher"].as!string);
        writeln("Genre: ", record["genre"].as!string); writeln();
    }
    writeln("================END=================");
}

void select_by_publisher(Database db, string* publisher) {}