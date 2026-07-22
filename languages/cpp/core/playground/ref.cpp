#include <iostream>
#include <functional>


int main() {
    int a = 5;
    int b = 10;
    int c = 3;
    int&& r = (c > 5 ? a : std::ref(b));

    std::cout << "r = " << r << std::endl; // Output: r = 5

    return 0;
}