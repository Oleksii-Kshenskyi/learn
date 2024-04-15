#include <iostream>

struct A {
    A() {
        std::cout << "Constructing A..." << std::endl;
    }
    ~A() {
        std::cout << "Destructing A..." << std::endl;
    }
};

struct B: public A {
    B() {
        std::cout << "Constructing B..." << std::endl;
    }
    ~B() {
        std::cout << "Destructing B..." << std::endl;
    }
};

int main() {
    A* ptr = new B();
    delete ptr;
    return 0;
}