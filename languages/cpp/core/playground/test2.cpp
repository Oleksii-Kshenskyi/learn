#include <iostream>
#include <iomanip>
#include <cstring>
//int* ptr - passes int (the value) itself by pointer,
//           but passes the pointer by VALUE!!
void reallocate(int* ptr, int new_value) {
    std::cout << "ptr INSIDE of reallocate (before): " << ptr << std::endl;
    std::cout << "address of ptr ITSELF (main, INSIDE realloc): " << &ptr << std::endl;
    delete ptr;
    ptr = new int;
    *ptr = new_value;
}

// int* return_bugged() {
//     int x = 5;
//     int p = (unsigned int)&x;
//     std::cout << "value of x(inside bugged): " << x << ", address of x: " << &x << std::endl;
//     std::cout << std::hex << "value of p(inside bugged): " << p  << std::dec << ", address of p: " << &p << std::endl;
//     return &p;
// }

int main() {
    std::cout << "HEllo Visual Studio!" << std::endl;

    int* ptr = new int;
    *ptr = 3;
    std::cout << "ptr in main (before entering reallocate): " << ptr << ", value: " << *ptr << std::endl;
    std::cout << "address of ptr ITSELF (main, before realloc call): " << &ptr << std::endl;
    reallocate(ptr, 8001);

    //delete ptr;
    //ptr = new int;
    //*ptr = 8001;
    std::cout << "ptr: " << ptr << ", value: " << *ptr << std::endl;

    delete ptr;


    // int* bugged_ptr = return_bugged();
    // std::cout << "bugged_ptr address: " << bugged_ptr << std::endl;
    // std::cout << "trying to access bugged ptr's value: " << std::hex << *bugged_ptr << std::dec << std::endl;



    // char** array_of_strings = new char* [4];
    
    // array_of_strings[0] = new char[30];
    // strcpy(array_of_strings[0], "HEllo 0!");

    // getchar();
    return 0;
}

// int main_2() {
//     char** array_of_strings = new char* [4];
//     // char[4][100] array_of_strings;

//     array_of_strings[0] = new char[30];
//     strcpy(array_of_strings[0], "HEllo 0!");
//     std::cout << "arr[0]: " << array_of_strings[0] << std::endl;

//     array_of_strings[1] = new char[100];
//     strcpy(array_of_strings[1], "HEllo 1! ionwebonewopbneon");
//     std::cout << "arr[1]: " << array_of_strings[1] << std::endl;

//     array_of_strings[2] = new char[200];
//     strcpy(array_of_strings[2], "HEllo 2! nnineinfknefk KEKW");
//     std::cout << "arr[2]: " << array_of_strings[2] << std::endl;

//     array_of_strings[3] = new char[300];
//     strcpy(array_of_strings[3], "HEllo 3! benbopnesopbseonbonsebosnebonesonbosnebonsebposenobnseponbsonbosnebon");
//     std::cout << "arr[3]: " << array_of_strings[3] << std::endl;
   

//     delete[] array_of_strings[0];
//     delete[] array_of_strings[1];
//     delete[] array_of_strings[2];
//     delete[] array_of_strings[3];
//     delete[] array_of_strings;
//     // getchar();
//     return 0;
// }