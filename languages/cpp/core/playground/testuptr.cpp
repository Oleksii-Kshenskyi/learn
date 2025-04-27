#include <iostream>
#include <memory>
#include <map>

class Command {
    public:
        virtual void execute() = 0;
        virtual ~Command() = default;
};

class ConcreteCommand : public Command {
    public:
        void execute() override {
            std::cout << "Executing ConcreteCommand E\n";
        }
};

int main() {
    std::map<std::string, std::unique_ptr<Command>> commands;
    // commands["c"] = std::make_unique<ConcreteCommand>();
    commands.emplace("e", std::make_unique<ConcreteCommand>());

    commands["e"]->execute();
    return 0;
}