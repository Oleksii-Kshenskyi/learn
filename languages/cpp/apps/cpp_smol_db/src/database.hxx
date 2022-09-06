#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <string>
#include <soci/soci.h>
#include <soci/sqlite3/soci-sqlite3.h>

using namespace soci;

class Database {
    private:
        session _db;

    public:
        Database(): _db(soci::session(sqlite3, "database.db")) {}

        void list_records() {}
        void write_new_record() {}
        void lookup_by_title(const std::string& title) { (void) title; }
        void lookup_by_developer(const std::string& developer) { (void) developer; }
        void lookup_by_publisher(const std::string& publisher) { (void) publisher; }
};

#endif // DATABASE_HXX