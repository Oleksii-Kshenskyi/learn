#pragma once

#include <memory>

#include "ishuffler.hpp"

namespace shuffler::lib
{
   class StdRandomShuffler: public IShuffler
   {
      public:
         StdRandomShuffler(std::unique_ptr<IRNG>&& new_rng): rng(std::move(new_rng))
         {}
         virtual std::string shuffle_string(const std::string& str) override
         {
            std::string shuffled { str };
            for(auto index { 0 }; index < shuffled.length(); index++)
            {
               auto random_index { rng->generate_between(0, shuffled.length()) };
               std::swap(shuffled[index], shuffled[random_index]);
            }
            return shuffled;
         }
      private:
         std::unique_ptr<IRNG> rng;
   };
}