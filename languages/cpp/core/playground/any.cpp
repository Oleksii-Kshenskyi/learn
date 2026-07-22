#include <print>
#include <any>
#include <vector>
#include <string>


int main() {
    std::println("Oh boi, here we gooo");
    std::vector<std::any> vec { 1, std::string{"2"}, static_cast<bool>(3)};

    int a = std::any_cast(vec[0]);

    // std::println("1 = {}, 2 = {}, 3 = {}", vec[0], vec[1], vec[2]);
    // std::any as { std::string { "hello" }};
    // std::any ab { static_cast<bool>(1)};
    // std::any ai { 3 };

    // std::println("1 = {}, 2 = {}, 3 = {}", std::any_cast<std::string>(as), std::any_cast<bool>(ab), std::any_cast<int>(ai));
    
    return 0;
}