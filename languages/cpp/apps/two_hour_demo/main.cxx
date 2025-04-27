#include <iostream>
#include "commandline.hxx"

// ./dtime subdiff <diff1> <diff2>
// ./dtime adddiff <diff1> <diff2>
// ./dtime datediff <date1> <date2> // in days

int main(int argc, char** argv) {
    auto args = new_args(argc, argv);
    std::cout << "Are args valid?" << args.valid << std::endl;
    return 0;
}