#ifndef DATABASE_HXX
#define DATABASE_HXX

#include <string>

class Database {
    private:
        std::string _db;

    public:
        Database(std::string&& new_db): _db(new_db) {}

        void list_records() {}
        void write_new_record() {}
        void lookup_by_title(const std::string& title) {}
        void lookup_by_developer(const std::string& developer) {}
        void lookup_by_publisher(const std::string& publisher) {}

        ~Database() {
            this->_db.close();
        }
};

#endif // DATABASE_HXX