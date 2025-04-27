#include <iostream>
#include <type_traits>

struct Nums {
    int a;
    int b;
    int c;
};

int sum_of_nums(Nums nums) {
    return nums.a + nums.b + nums.c;
}

template<typename T>
void print_ref_info(T&& check_val) {
    std::cout << "is " << check_val << " a ref? => " << std::is_reference_v<T> << " is: " << typeid(check_val).name() << std::endl;
}

int main() {
    //char* test = new char[30];
    //std::cout << "Allocated string on heap, address: " << (void*)test << std::endl;
    //std::cout << "Now trying to 'just assign' a value to it..." << std::endl;
    //test = {"Waaaagh!!"};
    //std::cout << "Assigned value to string on heap, address: " << (void*)test << std::endl;
    //std::cout << "Now stupidly trying to change the value..." << std::endl;
    //test[0] = 'B';
    //std::cout << "Changed value of string on heap, address: " << (void*)test << std::endl; // this is a crash

    auto b = 3;
    auto b2 = 3ULL;
    auto c = 3.14;
    auto f = 3.14f;
    auto kek = "kekw";
    //auto nope;
    auto p = &b;
    auto pp = &p;
    auto& r = b;
    r += 3;
    std::cout << &r << std::endl;
    std::cout << &b << std::endl;

    std::cout << "type of " << b << " is: " << typeid(b).name() << std::endl;
    std::cout << "type of " << b2 << " is: " << typeid(b2).name() << std::endl;
    std::cout << "type of " << c << " is: " << typeid(c).name() << std::endl;
    std::cout << "type of " << f << " is: " << typeid(f).name() << std::endl;
    std::cout << "type of " << kek << " is: " << typeid(kek).name() << std::endl;
    std::cout << "type of " << p << " is: " << typeid(p).name() << std::endl;
    std::cout << "type of " << pp << " is: " << typeid(pp).name() << std::endl;
    std::cout << "type of (r) " << r << ", is: " << typeid(r).name() << std::endl;
    print_ref_info(r);
    std::cout << "It also is: " << typeid(r).name() << std::endl;



    system("pause");
    return 0;
}