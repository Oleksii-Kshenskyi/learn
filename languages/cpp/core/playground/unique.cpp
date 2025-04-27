#include <iostream>
#include <memory>

struct ProxyInt {
    int x = 0;
    int y = 0;
};

class MyClass {
public:
    MyClass() { std::cout << "MyClass created\n"; }
    ~MyClass() { std::cout << "MyClass destroyed\n"; }
    void doSomething() { std::cout << "Doing something\n"; }
};

int main() {
    // Create a unique_ptr that owns a MyClass instance.
    std::unique_ptr<MyClass> ptr = std::make_unique<MyClass>();
    
    // Use the object via the unique_ptr.
    ptr->doSomething();
    
    // Demonstrate transfer of ownership.
    std::unique_ptr<MyClass> ptr2 = std::move(ptr);
    if (!ptr) {
        std::cout << "ptr is now null after move\n";
    }

    ProxyInt pis[10];
    new (&pis[1]) ProxyInt {13, 15};
    new (&pis[9]) ProxyInt {66, 99};
    std::cout << "pis[1].x: " << pis[1].x << ", pis[1].y: " << pis[1].y << "\n";
    std::cout << "pis[9].x: " << pis[9].x << ", pis[9].y: " << pis[9].y << "\n";

    
    // ptr2 goes out of scope at the end of main,
    // and the MyClass object is automatically destroyed.
    return 0;
}
