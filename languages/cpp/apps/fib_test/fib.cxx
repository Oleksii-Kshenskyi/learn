#include <iostream>
#include <cstdint>

uint64_t fib(uint64_t n) {
    if(n == 0 || n == 1) { return n; } else { return fib(n - 1) + fib(n - 2); }
}

int main() {
    uint64_t n = 42;
    std::cout << "Fib " << n << " is " << fib(n) << std::endl;

    return 0;
}