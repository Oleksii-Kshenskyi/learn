#include <memory>
#include <random>

#include "irng.hpp"

namespace shuffler::lib
{
   class StandardLibRNG: public IRNG
   {
      public:
         StandardLibRNG(): m_random_device(), m_mt(m_random_device())
         {}
         virtual unsigned int generate_between(unsigned int lower_bound, unsigned int upper_bound) override
         {
            std::uniform_int_distribution<> distribution(lower_bound, upper_bound);
            return distribution(m_mt);
         }
      private:
         std::random_device m_random_device;
         std::mt19937 m_mt;
   };
}