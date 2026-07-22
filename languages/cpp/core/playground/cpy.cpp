#include <iostream>

struct Person {
    std::string name;
    unsigned short age;
    unsigned short height;

    Person(): name("DEFAULT"), age(0), height(0) {}
    Person(std::string nname, unsigned short nage, unsigned short nheight)
    : name(nname), age(nage), height(nheight) {}
    Person(const Person& other): name(other.name), age(other.age), height(other.height) {}

    void show() {
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Age: " << this->age << std::endl;
        std::cout << "Height: " << this->height << std::endl;
    }
};

int main() {
    Person p1 { "P1", 1, 1};
    Person p2 { "P2", 2, 2};

    p2 = p1;
    p2.show();



    return 0;
}