#include "lib/todo.hxx"

std::string TodoMaster::read(std::vector<std::string> args) {
        if(args.size() != 0) {
            return "ERROR: the read command doesn\'t accept any arguments.\n";
        }
        std::vector<std::string> todos;
        std::ifstream todo_file(todo_filename, std::ios::in);
        std::string line;
        while(std::getline(todo_file, line)) {
            todos.push_back(line);
        }

        std::stringstream ssread;
        for(auto item: todos) {
            ssread << item << "\n";
        }
        return ssread.str();
}

std::string TodoMaster::write(std::vector<std::string> args) {
    if(args.size() != 1) {
        return "ERROR: the `write` command is expecting exactly one argument, a new TODO note.\n";
    }
    std::ofstream todo_file(todo_filename, std::ios::app);
    todo_file << args[0] << "\n";
    return "Successfully wrote your TODO item to the file!\n";
}