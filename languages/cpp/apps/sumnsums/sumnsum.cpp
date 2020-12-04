#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cstdlib>

int sum_once(const std::vector<int>& sum_this) {
   return std::accumulate(sum_this.begin(), sum_this.end(), 0);
}

int main(int argc, char** argv) {
   // get a vector of strings from command line
   std::vector<std::string> vec_argv(argv + 1, argv + argc);

   std::vector<int> vec_of_nums;
   try {
      // convert the vector of strings to ints
      std::transform(vec_argv.begin(), vec_argv.end(), std::back_inserter(vec_of_nums), [](const std::string& str_elem) {
         return std::stoi(str_elem);
      });
   }
   catch(std::invalid_argument& err) {
      std::cout << "NOPE: " << err.what() << ": conversion string->int failed!" << std::endl;
      std::cout << "Command line arguments should only consist of valid integer numbers! Try again!" << std::endl;
      exit(1);
   }

   // print the vector of nums
   std::cout << "The current vector is: ";
   std::copy(vec_of_nums.begin(), vec_of_nums.end(), std::ostream_iterator<int>(std::cout, " "));
   std::cout << std::endl;

   // create vec of sums and output its sum:
   std::vector<int> vec_of_sums;
   for(auto iter = vec_of_nums.begin(); iter != vec_of_nums.end(); iter++) {
      vec_of_sums.emplace_back(
         std::accumulate(vec_of_nums.begin(), iter + 1, 0)
      );
   }
   long long the_sum = std::accumulate(vec_of_sums.begin(), vec_of_sums.end(), 0);

   std::cout << "Sum of nth sums Pogomega?! => " << the_sum << std::endl;
   return 0;
}