#include <iostream>
#include "shuffler_cli_argument_validator.hpp"

using namespace shuffler::lib;

int main(int argc, char** argv)
{
   std::cout << "Hello C++ Shuffler World!" << std::endl;
   std::string shuffle_me { "herrhotzenplotz" };
   
   ShufflerCLIArgumentValidator validator;
   auto validation_response = validator.validate_and_process_command_line(argc, argv);
   if(validation_response.error_type != CLIArgErrorType::OK)
   {
      std::cout << "ERROR: " << validation_response.error_message << std::endl;
      return -1;
   }
   
   CLIArgs received_args { validator.get_command_line_arguments() };
   std::cout << "Actually received arguments Pog!" << std::endl;
   std::cout << "The string to be shuffled: " << received_args.string_to_shuffle << std::endl;
   std::cout << "The number of shuffles to be displayed: " << received_args.number_of_shuffles << std::endl;

   return 0;
}