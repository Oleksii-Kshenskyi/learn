#include <iostream>
#include "standard_lib_rng.hpp"

int main()
{
   std::cout << "Hello C++ Shuffler World!" << std::endl;
   shuffler::lib::StandardLibRNG rng;

   std::cout << "Generating between [0, 120): " << rng.generate_between(0, 120) << std::endl;
   std::cout << "Generating between [10, 22): " << rng.generate_between(10, 22) << std::endl;
   std::cout << "Generating between [1000, 1000000): " << rng.generate_between(1000, 1000000) << std::endl;
   std::cout << "Generating between [0, 3000000000): " << rng.generate_between(0, 3000000000) << std::endl;
}