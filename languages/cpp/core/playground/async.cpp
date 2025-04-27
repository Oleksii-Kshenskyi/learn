#include <iostream>
#include <future>
#include <thread>
#include <chrono>


void CALCULATESIME_B(bool &data){
    std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    data = true;
    printf("thread done!\n");
    return;
}

int main() {

    bool boo = false;

    std::future<void> result = std::async(std::launch::async, CALCULATESIME_B, std::ref(boo));

   // std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    std::cout << boo << std::endl;
    result.wait();
    std::cout << boo << std::endl;

    return 0;
}