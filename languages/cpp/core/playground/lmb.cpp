#include <iostream>
#include <algorithm>
#include <vector>

bool isEven(int i) {
    return i % 2 == 0;
}

int main() {
    std::vector<int> v = {-1, 1, 2, 3, 4, 5, 11};
    std::cout << "Are all elements even? => " << std::all_of(v.begin(), v.end(), [](int i) { return i % 2 == 0; }) << std::endl;

    std::cout << "Are all elements even (func ptr)? => " << std::all_of(v.begin(), v.end(), isEven) << std::endl;

    std::cout << "Count even: " << std::count_if(v.begin(), v.end(), [](int i) { return i % 2 == 0; }) << std::endl;
    std::cout << "Now count negative: " << std::count_if(v.begin(), v.end(), [](int i) { return i < 0; }) << std::endl;
    std::cout << "Now count >10: " << std::count_if(v.begin(), v.end(), [](int i) -> bool { return i > 10; }) << std::endl;

    return 0;
}