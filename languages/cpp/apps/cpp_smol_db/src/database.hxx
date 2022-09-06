#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <string>
#include <fmt/core.h>
#include <iostream>
#include <vector>
#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

using namespace soci;

class Database {
    private:
        session _db;

    public:
        Database(): _db(soci::session(sqlite3, "database.db")) {
            this->_db << "CREATE TABLE IF NOT EXISTS videogame("
                      << "id INTEGER PRIMARY KEY AUTOINCREMENT,"
                      << "title TEXT NOT NULL,"
                      << "year INTEGER,"
                      << "developer TEXT,"
                      << "publisher TEXT,"
                      << "genre TEXT"
                    << ")";
        }

        void select_query_and_out(std::string count_message,
                                  std::string output_header,
                                  std::string count_query,
                                  std::string select_query) {
            int games_count = 0;
            this->_db << count_query, into(games_count);
            std::cout << count_message << ": " << games_count << std::endl;

            std::vector<int> ids; ids.resize(100);
            std::vector<std::string> titles; titles.resize(100);
            std::vector<int> years; years.resize(100);
            std::vector<std::string> developers; developers.resize(100);
            std::vector<std::string> publishers; publishers.resize(100);
            std::vector<std::string> genres; genres.resize(100);
            this->_db << select_query, into(ids), into(titles), into(years), into(developers), into(publishers), into(genres);

            std::cout << "==============" << output_header << "==============" << std::endl << std::endl;
            for(std::size_t i = 0; i < ids.size(); i++) {
                std::cout << "Videogame {" << std::endl;
                std::cout << "    ID: '" << ids[i] << "'," << std::endl;
                std::cout << "    Game's title: '" << titles[i] << "'," << std::endl;
                std::cout << "    Game's year of release: '" << years[i] << "'," << std::endl;
                std::cout << "    Game's developer: '" << developers[i] << "'," << std::endl;
                std::cout << "    Game's publisher: '" << publishers[i] << "'," << std::endl;
                std::cout << "    Game's genre: '" << genres[i] << "'," << std::endl;
                std::cout << "}" << std::endl << std::endl;
            }
            std::cout << "============END " << output_header << "=============" << std::endl;
        }

        void list_records() {
            this->select_query_and_out(
                "Games in the database",
                "VIDEOGAMES",
                "SELECT count(*) FROM videogame",
                "SELECT * FROM videogame"
            );
        }
        void write_new_record() {
            std::cout << "Please provide some info about a video game..." << std::endl;
            std::string title; std::cout << "Game's title? => "; std::getline(std::cin, title);
            std::string year_str; std::cout << "Game's year of release? => "; std::getline(std::cin, year_str); auto year = std::stoi(year_str);
            std::string developer; std::cout << "Game's developer studio name? => "; std::getline(std::cin, developer);
            std::string publisher; std::cout << "Game's publisher? => "; std::getline(std::cin, publisher);
            std::string genre; std::cout << "Game's genre? => "; std::getline(std::cin, genre);

            this->_db << "INSERT INTO videogame(title, year, developer, publisher, genre) VALUES (:title, :year, :developer, :publisher, :genre)", use(title), use(year), use(developer), use(publisher), use(genre);
        }

        void lookup_by_title(const std::string& title) { 
            this->select_query_and_out(
                fmt::format("Games in the database with title [{}]", title),
                "SEARCH BY TITLE",
                fmt::format("SELECT count(*) FROM videogame WHERE title LIKE '%{}%'", title),
                fmt::format("SELECT * FROM videogame WHERE title LIKE '%{}%'", title)
            );
        }

        void lookup_by_developer(const std::string& developer) {
            this->select_query_and_out(
                fmt::format("Games in the database with developer studio name containing [{}]", developer),
                "SEARCH BY DEV",
                fmt::format("SELECT count(*) FROM videogame WHERE developer LIKE '%{}%'", developer),
                fmt::format("SELECT * FROM videogame WHERE developer LIKE '%{}%'", developer)
            );
        }

        void lookup_by_publisher(const std::string& publisher) {
            this->select_query_and_out(
                fmt::format("Games in the database with publisher name containing [{}]", publisher),
                "SEARCH BY PUB",
                fmt::format("SELECT count(*) FROM videogame WHERE publisher LIKE '%{}%'", publisher),
                fmt::format("SELECT * FROM videogame WHERE publisher LIKE '%{}%'", publisher)
            );
        }
};

#endif // DATABASE_HXX