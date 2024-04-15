#include <iostream>
#include <algorithm>
#include <vector>


int main() {
    std::vector<int> vi = {1, 2, 3, 4};
    std::vector<int> vd = {};

    std::cout << "Equal? => " << std::equal(vi.begin(), vi.end(), vd.begin());

    return 0;
}