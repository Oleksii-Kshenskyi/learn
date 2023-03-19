#include "lib/system.hxx"
#include "lib/cli.hxx"

int main(int argc, char** argv) {
    std::cout << CLICommands(argc, argv).run() << std::endl;
    return 0;
}