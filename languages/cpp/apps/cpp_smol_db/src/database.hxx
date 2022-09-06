#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <string>
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

        void list_records() {
            int games_count = 0;
            this->_db << "SELECT count(*) FROM videogame", into(games_count);
            std::cout << "Games in the database: " << games_count << std::endl;

            std::vector<int> ids; ids.resize(100);
            std::vector<std::string> titles; titles.resize(100);
            std::vector<int> years; years.resize(100);
            std::vector<std::string> developers; developers.resize(100);
            std::vector<std::string> publishers; publishers.resize(100);
            std::vector<std::string> genres; genres.resize(100);
            this->_db << "SELECT * FROM videogame", into(ids), into(titles), into(years), into(developers), into(publishers), into(genres);

            std::cout << "==============VIDEOGAMES==============" << std::endl << std::endl;
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
            std::cout << "============END VIDEOGAMES=============" << std::endl;
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
            int games_count = 0;
            this->_db << "SELECT count(*) FROM videogame WHERE title LIKE '%" << title << "%'", into(games_count);
            std::cout << "Games in the database with title [" << title << "]: " << games_count << std::endl;

            std::vector<int> ids; ids.resize(100);
            std::vector<std::string> titles; titles.resize(100);
            std::vector<int> years; years.resize(100);
            std::vector<std::string> developers; developers.resize(100);
            std::vector<std::string> publishers; publishers.resize(100);
            std::vector<std::string> genres; genres.resize(100);
            this->_db << "SELECT * FROM videogame WHERE title LIKE '%" << title << "%'", into(ids), into(titles), into(years), into(developers), into(publishers), into(genres);

            std::cout << "===========SEARCH BY TITLE==========" << std::endl << std::endl;
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
            std::cout << "========END SEARCH BY TITLE=========" << std::endl;
        }

        void lookup_by_developer(const std::string& developer) {
            int games_count = 0;
            this->_db << "SELECT count(*) FROM videogame WHERE developer LIKE '%" << developer << "%'", into(games_count);
            std::cout << "Games in the database by developer studio [" << developer << "]: " << games_count << std::endl;

            std::vector<int> ids; ids.resize(100);
            std::vector<std::string> titles; titles.resize(100);
            std::vector<int> years; years.resize(100);
            std::vector<std::string> developers; developers.resize(100);
            std::vector<std::string> publishers; publishers.resize(100);
            std::vector<std::string> genres; genres.resize(100);
            this->_db << "SELECT * FROM videogame WHERE developer LIKE '%" << developer << "%'", into(ids), into(titles), into(years), into(developers), into(publishers), into(genres);

            std::cout << "=============SEARCH BY DEV=============" << std::endl << std::endl;
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
            std::cout << "===========END SEARCH BY DEV============" << std::endl;
        }

        void lookup_by_publisher(const std::string& publisher) { (void) publisher;
            int games_count = 0;
            this->_db << "SELECT count(*) FROM videogame WHERE publisher LIKE '%" << publisher << "%'", into(games_count);
            std::cout << "Games in the database by publisher [" << publisher << "]: " << games_count << std::endl;

            std::vector<int> ids; ids.resize(100);
            std::vector<std::string> titles; titles.resize(100);
            std::vector<int> years; years.resize(100);
            std::vector<std::string> developers; developers.resize(100);
            std::vector<std::string> publishers; publishers.resize(100);
            std::vector<std::string> genres; genres.resize(100);
            this->_db << "SELECT * FROM videogame WHERE publisher LIKE '%" << publisher << "%'", into(ids), into(titles), into(years), into(developers), into(publishers), into(genres);

            std::cout << "==============SEARCH BY PUB==============" << std::endl << std::endl;
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
            std::cout << "============END SEARCH BY PUB=============" << std::endl;
        }
};

#endif // DATABASE_HXX