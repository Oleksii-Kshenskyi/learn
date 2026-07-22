#include <print>

template<typename T>
struct AllocKEKW {
    alignas(T) unsigned char storage[sizeof(T)];
};

int main() {
    AllocKEKW<int> t;

    *(t.storage) = 3;
    std::println("Storage? => {}", *(t.storage));
    return 0;
}