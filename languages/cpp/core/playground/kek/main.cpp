#include <iostream>

int ret(int x) {
    std::cout << "KEKW" << std::endl;
    return x;
}

int main() {
    std::cout << "Let's try this "
              << ret(10)
              << std::endl;
    
    getchar();
    return 0;
}