#include <iostream>

class A {
    public:
        A() { std::cout << "A constructor\n"; }
        virtual ~A() { std::cout << "A destructor\n"; }
};

class B : public A {
    public:
        B() { std::cout << "B constructor\n"; }
        ~B() { std::cout << "B destructor\n"; }
};

int main() {
    A* a = new B(); // Create an object of type B, but reference it as type A
    delete a; // This will call the destructor of A, but not B's destructor
    return 0;
}