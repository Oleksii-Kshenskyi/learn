// #include <iostream>

// constexpr int K = 1000;
// constexpr int ITER_COUNT = 10 * K;

// void test_heap() {
//     int* i1 = new int; *i1 = 3;
//     int* i2 = new int; *i2 = 8;
//     std::cout << i1 << " " << i2 << std::endl;
// }

// void test_near() {}

// int main() {
//     test_heap();
//     std::cout << "Testing Testing! " << ITER_COUNT << std::endl;
//     return 0;
// }

#include <iostream>
#include <vector>
#include <chrono>

constexpr size_t K = 1000;
constexpr size_t num_nodes = 60 * K;
constexpr size_t padding = K * K;

struct Node {
    size_t value;
    Node* next;
};

void test_list() {
    std::vector<char*> allocations;

    // Allocate nodes with padding
    Node* head = nullptr;
    Node* current = nullptr;
    for (size_t i = 0; i < num_nodes; ++i) {
        char* block = new char[sizeof(Node) + padding];
        allocations.push_back(block);
        Node* node = new (block) Node{i, nullptr}; // Placement new

        if (head == nullptr) {
            head = node;
        } else {
            current->next = node;
        }
        current = node;
    }

    // Test access times
    auto start = std::chrono::high_resolution_clock::now();
    Node* it = head;
    volatile int sum = 0;
    while (it != nullptr) {
        sum += it->value; // Volatile to prevent optimizations
        it = it->next;
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    std::cout << "\n\n=========List access test, " << num_nodes << " elements ==========" << std::endl;
    std::cout << "Time taken: " << diff.count() << " s\n";
    std::cout << "Sum: " << sum << std::endl;

    // Cleanup
    for (char* block : allocations) {
        delete[] block;
    }
}

void test_vec() {
    std::vector<char> test_vec;
    test_vec.reserve(num_nodes);
    test_vec.resize(num_nodes);
    std::cout << "Test vec size: " << test_vec.size() << std::endl;
    std::fill(test_vec.begin(), test_vec.end(), 1);

    // Test access times
    auto start = std::chrono::high_resolution_clock::now();
    volatile size_t sum = 0;
    for (size_t index = 0; index < test_vec.size(); index++) {
        sum += test_vec[index]; // Volatile to prevent optimizations
    }
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    std::cout << "\n\n=========Vector access test, " << num_nodes << " elements ==========" << std::endl;
    std::cout << "Time taken: " << diff.count() << " s\n";
    std::cout << "Sum: " << sum << std::endl;
}

int main() {
    test_vec();
    return 0;
}