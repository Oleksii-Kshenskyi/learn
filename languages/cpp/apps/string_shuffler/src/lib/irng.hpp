namespace shuffler::lib 
{
   class IRNG 
   {
      public:
         virtual unsigned int generate_between(unsigned int lower_bound, unsigned int upper_bound) = 0;
   };
}