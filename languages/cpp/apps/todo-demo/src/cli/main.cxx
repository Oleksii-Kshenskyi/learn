#include "lib/system.hxx"
#include "lib/test.hxx"

// TODO: refactor/decouple code into the lib and their own classes

int main(int argc, char** argv) {
    std::vector<std::string> args(argv, argv + argc);
    
    if(args.size() < 2) {
        std::cout << "ERROR! Expecting at least 1 argument, the command name.\nUsage: todo <read|write> [<ARG>]" << std::endl;
        return 1;
    }
    if(args[1] == "read") {
        std::vector<std::string> todos;
        std::ifstream todo_file("todo.txt", std::ios::in);
        std::string line;
        while(std::getline(todo_file, line)) {
            todos.push_back(line);
        }

        std::copy(todos.begin(), todos.end(), std::ostream_iterator<std::string>(std::cout, "; "));
        std::cout << std::endl;
    } else if(args[1] == "write") {
        if(args.size() != 3) {
            std::cout << "ERROR: the `write` command is expecting exactly one argument, a new TODO note." << std::endl;
            return 1;
        }
        std::ofstream todo_file("todo.txt", std::ios::app);
        todo_file << args[2] << "\n";
    } else {
        std::cout << "ERROR: " << args[1] << ": unknown command." << std::endl;
        return 1;
    }
    return 0;
}