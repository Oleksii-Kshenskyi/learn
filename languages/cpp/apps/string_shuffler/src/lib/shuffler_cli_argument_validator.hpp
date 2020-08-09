#pragma once

#include <stdexcept>

#include "icli_argument_validator.hpp"

namespace shuffler::lib
{
   class ShufflerCLIArgumentValidator: public ICLIArgumentValidator
   {
      public:
         virtual ValidationResponse validate_and_process_command_line(int argc, char** argv) override
         {
            if(argc != 3)
               return { CLIArgErrorType::WrongNumberOfArgs, "Expected two arguments from command line." };
            
            parsed_args.string_to_shuffle = std::string(argv[1]);
            if(parsed_args.string_to_shuffle.empty())
               return { CLIArgErrorType::StringIsEmpty, "String argument for shuffling cannot be empty."};

            try
            {
               parsed_args.number_of_shuffles = std::stoul(std::string(argv[2]));
            }
            catch (const std::exception&)
            {
               return { CLIArgErrorType::SecondArgNotANumber, "Second argument should be an unsigned integer number." };
            }

            return { CLIArgErrorType::OK, "" };
         }
         virtual CLIArgs get_command_line_arguments() override
         {
            if(error_type == CLIArgErrorType::OK)
               return parsed_args;
            else
               throw std::invalid_argument("An attempt was made to get CLI args, which is impossible because of incorrect input from command line.");
         }
      private:
         CLIArgs parsed_args;
         CLIArgErrorType error_type;
   };
}