#include <iostream>
#include <thread>
#include <vector>
#include <mutex>
#include <ctime>

#define CAPACITY 10000

void worker_thread(std::vector<int>& vec, std::mutex& m, size_t& counter, size_t start, size_t end) {
    for (size_t i = start; i < end; ++i) {
        vec[i] *= 2;
        m.lock();
        counter++;
        m.unlock();
    }
}

int main() {
    srand(time(NULL));

    std::vector<int> v;
    v.reserve(CAPACITY);
    v.resize(CAPACITY);
    for (auto& el : v) {
        el = rand() % 5000;
    }

    auto threads_count = std::thread::hardware_concurrency();
    std::cout << "Threads: " << threads_count << std::endl;
    size_t range = CAPACITY / threads_count;

    std::vector<std::thread*> threads;
    std::mutex m;
    size_t c = 0;
    for (int i = 0; i < threads_count; ++i) {
        int start = i * range;
        int end = 0;
        if (i + 1 == threads_count) {
            end = v.size();
        }
        else {
            end = i * range + range;
        }
        threads.push_back(new std::thread(worker_thread, std::ref(v), std::ref(m), std::ref(c), start, end));
    }
    
    for (auto& t : threads) {
        t->join();
        delete t;
    }
    std::cout << "Total count: " << c << std::endl;
    system("pause");
    return 0;
}