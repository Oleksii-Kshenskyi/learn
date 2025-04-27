#include <iostream>

struct ProxyInt {
    int x;
    int y;
    ProxyInt() : x(0), y(0) {
        std::cout << "Default constructor called\n";
    }
    ProxyInt(int a, int b) : x(a), y(b) {
        std::cout << "Parameterized constructor called\n";
    }
    ~ProxyInt() {
        std::cout << "Destructor called for ProxyInt(" << x << ", " << y << ")\n";
    }
};

int main() {
    // Allocate an array of ProxyInt, default-constructed.
    ProxyInt pis[10];
    
    // Explicitly destroy the object at index 1.
    pis[1].~ProxyInt();
    // At this point, pis[1] is not a valid object (its memory is still allocated but uninitialized).
    
    // Reconstruct the object in place using placement new.
    new (&pis[1]) ProxyInt(13, 15);
    
    // For demonstration, similarly reinitialize element at index 9.
    pis[9].~ProxyInt();
    new (&pis[9]) ProxyInt(66, 99);
    
    std::cout << "pis[1].x: " << pis[1].x << ", pis[1].y: " << pis[1].y << "\n";
    std::cout << "pis[9].x: " << pis[9].x << ", pis[9].y: " << pis[9].y << "\n";
    
    // The rest of the array remains valid as initially constructed.
    return 0;
}