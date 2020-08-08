#pragma once

#include <memory>

#include "standard_lib_rng.hpp"

namespace shuffler::lib 
{
   class IShuffler
   {
      public:
         virtual std::string shuffle_string(const std::string& str) = 0;
   };
}