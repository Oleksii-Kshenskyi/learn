#include "lib/system.hxx"

class TodoMaster {
    public:
        TodoMaster(): todo_filename("todo.txt") {}
        std::string read(std::vector<std::string> args);
        std::string write(std::vector<std::string> args);
        std::string delete_(std::vector<std::string> args);
    private:
        const std::string todo_filename;
};