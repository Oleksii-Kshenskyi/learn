#include <iostream>
#include <vector>

class PushbackTester {
    public:
        int index = 0;
        PushbackTester(int index): index(index) {
            std::cout << "[" << index << "] PushbackTester::PushbackTester(int) [" << this << "]" << std::endl;
        }

        PushbackTester(PushbackTester&& other) noexcept : index(other.index) {
            std::cout << "[" << index << "] [MOVE] PushbackTester::PushbackTester(PushbackTester&&) [" << this << "]" << std::endl;
        }

        PushbackTester(const PushbackTester& other) : index(other.index) {
            std::cout << "[" << index << "] [COPY] PushbackTester::PushbackTester(const PushbackTester&) [" << this << "]" << std::endl;
        }

        ~PushbackTester() {
            std::cout << "[" << index << "] PushbackTester::~PushbackTester() [" << this << "]" << std::endl;
        }
        
};

int main() {
    std::vector<PushbackTester> vec;
    for (int i = 0; i < 10; ++i) {
        std::cout << "Pushing element " << i << "..." << std::endl;
        vec.emplace_back(i);
        std::cout << "================\n\n";
    }
    
    std::cout << "\n\n Post-pushback..." << std::endl;
    std::cout << "Vector size: " << vec.size() << std::endl;
    std::cout << "Vector capacity: " << vec.capacity() << std::endl;
    return 0;
}