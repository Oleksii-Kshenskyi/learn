#pragma once

namespace shuffler::lib
{
   enum class CLIArgErrorType
   {
      OK,
      WrongNumberOfArgs,
      StringIsEmpty,
      SecondArgNotANumber
   };

   struct ValidationResponse
   {
      CLIArgErrorType error_type;
      std::string error_message;
   };

   struct CLIArgs
   {
      std::string string_to_shuffle;
      unsigned int number_of_shuffles;
   };

   class ICLIArgumentValidator {
      public:
         virtual ValidationResponse validate_and_process_command_line(int argc, char** argv) = 0;
         virtual CLIArgs get_command_line_arguments() = 0;
   };
}