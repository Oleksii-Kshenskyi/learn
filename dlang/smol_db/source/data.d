module data;

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



void select_and_print(Database db) {}
void insert_new_game(Database db) {}
void select_by_name(Database db, string* name) {}
void select_by_developer(Database db, string* developer) {}
void select_by_publisher(Database db, string* publisher) {}