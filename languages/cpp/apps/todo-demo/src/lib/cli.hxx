#pragma once

#include "lib/system.hxx"
#include "lib/todo.hxx"

class CLICommands {
    public:
        CLICommands(int argc, char** argv);
        std::string run();
    private:
        std::vector<std::string> args;
        TodoMaster todos;
        std::unordered_map<std::string, std::function<std::string(std::vector<std::string>)>> commands;
};