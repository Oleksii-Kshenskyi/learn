#include "lib/cli.hxx"

CLICommands::CLICommands(int argc, char** argv):
    args(argv, argv + argc), todos() {
    //[](<arg>, <arg>, ...) { <function body>; };
    commands["read"] = [&](std::vector<std::string> myargs) { return todos.read(myargs); };
    commands["write"] = [&](std::vector<std::string> myargs) { return todos.write(myargs); };
}

std::string CLICommands::run() {
    if(args.size() < 2) { return "ERROR! Expecting at least 1 argument, the command name.\nUsage: todo <read|write> [<ARG>]\n"; }
    if(commands.count(args[1]) == 0) { return (std::stringstream() << "ERROR: " << args[1] << ": unknown command.\n").str(); }

    std::vector<std::string> lambda_args(args.begin() + 2, args.end());
    return commands[args[1]](lambda_args);
}