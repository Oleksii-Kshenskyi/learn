#include <iostream>
#include "std_random_shuffler.hpp"

using namespace shuffler::lib;

int main()
{
   std::cout << "Hello C++ Shuffler World!" << std::endl;
   std::string shuffle_me { "herrhotzenplotz" };
   
   StdRandomShuffler shuffler(std::make_unique<StandardLibRNG>());
   std::cout << "First shuffle: " << shuffler.shuffle_string(shuffle_me) << std::endl;
   std::cout << "Second shuffle: " << shuffler.shuffle_string(shuffle_me) << std::endl;
   std::cout << "Third shuffle: " << shuffler.shuffle_string(shuffle_me) << std::endl;
   std::cout << "Fourth shuffle: " << shuffler.shuffle_string(shuffle_me) << std::endl;
   std::cout << "Fifth shuffle: " << shuffler.shuffle_string(shuffle_me) << std::endl;
}