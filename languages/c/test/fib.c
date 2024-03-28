#include <stdio.h>
#include <stdint.h>

uint64_t fib(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    uint64_t prev = 0, curr = 1;
    for (int i = 2; i <= n; i++) {
        uint64_t next = prev + curr;
        prev = curr;
        curr = next;
    }
    return curr;
}

int main() {
    int n = 42;
    printf("Fibonacci of %d is %llu\n", n, fib(n));
    return 0;
}