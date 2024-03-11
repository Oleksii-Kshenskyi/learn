#include <stdio.h>
#include <stdint.h>

uint64_t fib(uint64_t n) {
    if(n == 0 || n == 1) { return n; } else { return fib(n - 1) + fib(n - 2); }
}

int main() {
    uint64_t n = 42;
    printf("Fib %ull is %ull\n", n, fib(n));

    return 0;
}