#include "lib/todo.hxx"

std::string TodoMaster::read(std::vector<std::string> args) {
        if(args.size() != 0) {
            return "ERROR: the read command doesn\'t accept any arguments.";
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
        return "ERROR: the `write` command is expecting exactly one argument, a new TODO note.";
    }
    std::ofstream todo_file(todo_filename, std::ios::app);
    todo_file << args[0] << "\n";
    return "Successfully wrote your TODO item to the file!";
}

std::string TodoMaster::delete_(std::vector<std::string> args) {
    if(args.size() != 1) {
        return "ERROR: the `delete` command is expecting exactly one argument: the number of the TODO item to delete.";
    }
    size_t todo_index = 0;
    try {
        todo_index = (size_t) std::stoi(args[0]);
    } catch(...) {
        return "ERROR: the argument to the `delete` command should be a valid integer index.";
    }
    std::vector<std::string> todos;
    std::ifstream read_todo(todo_filename, std::ios::in);
    std::string line;
    while(std::getline(read_todo, line)) {
        todos.push_back(line);
    }
    if(todos.size() == 0) { return "ERROR: can't delete anything: the todo list is already empty."; }
    if(todo_index > todos.size()) { return ( std::stringstream() << "ERROR: there are only " << todos.size() << " TODOs in the file, but you're asking to delete the " << todo_index << "th TODO.").str(); }

    todos.erase(todos.begin() + (long) todo_index);

    std::ofstream write_todo(todo_filename, std::ios::ate);
    for(auto line: todos) {
        write_todo << line << "\n";
    }

    return (std::stringstream() << "Successfully deleted " << todo_index << "th TODO from the file.").str(); 
}