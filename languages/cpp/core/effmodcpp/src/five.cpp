#include <iostream>
#include <tuple>
#include <typeinfo>
#include <vector>

enum TestIt {
   a, b, c
};

bool enum_func(TestIt the_enum) 
{
   return the_enum == 0 ? false : true; // comparisons work directly with enums, but not with enum classes
}

void argument_check(char a, int b, double c)
{
   std::cout << "Yes indeed, a is " << a << "." << std::endl;
   std::cout << "Yes indeed, b is " << b << "." << std::endl;
   std::cout << "Yes indeed, c is " << c << "." << std::endl;
}

void cpp17_POGGERS()
{
   auto [a, b, c] { std::make_tuple('a', 1, 33.336) };
   std::cout << "a is " << a << " POGGERS" << std::endl;
   std::cout << "b is " << b << " POGGERS" << std::endl;
   std::cout << "c is " << c << " POGGERS" << std::endl;
   argument_check(a, b, c);
}

void types()
{
   std::string str { "KEKW" };
   std::vector v {1, 2, 3, 4, 5};
   auto [a, b, c] { std::make_tuple('a', 1, 33.44) };
   int& ir = b;
   int* ip = &b;
   std::cout << "STR: " << typeid(str).name() << std::endl;
   std::cout << "VEC: " << typeid(v).name() << std::endl;
   std::cout << "a, b, c: " << typeid(a).name() << ", " 
                            << typeid(b).name() << ", "
                            << typeid(c).name() << std::endl;
   std::cout << "ir: " << typeid(ir).name() << std::endl;
   std::cout << "ip: " << typeid(ip).name() << std::endl;
}

auto returns_auto_type_POGGERS(auto a1, auto a2)
{
   return a1 + a2; //NOTE: a1 and a2 being auto requires -fconcepts-ts enabled for now
}
void call_autofunc()
{
   std::cout << "AUTO RETURN VALUE WROKS POG: " << returns_auto_type_POGGERS(7, 5) << "!!!\n";
   std::cout << "AUTO RETURN VALUE WROKS WITH DIFFERENT TYPES PAGCHOMP: " << returns_auto_type_POGGERS(7, 5.1) << "!!!\n";
}

void lambdas()
{
   auto lmb { [](auto a, auto b) { return a + b; } };
   std::cout << "3 + 4 POG: " << lmb(3, 4) << std::endl;
   std::cout << "155 + 258 POG: " << lmb(155, 258) << std::endl;
   std::cout << "40 bln + 40 bln POG: " << lmb(40000000000, 40000000000) << std::endl;
   std::cout << "3 + 3.4 POG?.. " << lmb(3, 3.4) << std::endl;

   auto [a, b] { std::make_tuple(3, 4) };
   int a1 = a;

   std::cout << "a: " << a << std::endl;
   std::cout << "a1: " << a1 << std::endl;
   std::cout << "a1 == a: " << (a1 == a) << ".\n";
   std::cout << "b: " << b << std::endl;

   // auto cap1 = [](auto first, auto second) { a = 78; b = 79; }; // doesn't work, a and b not captured, error
   // auto cap2 = [=](auto first, auto second) { a = 78; b = 79; }; // error, a and b are read-only
   auto cap3 = [&](auto first, auto second) { a = 78; b = 79; }; // ok, a and b changed successfully
   // auto cap4 = [a, b](auto first, auto second) { a = 78; b = 79; }; // error, a and b are read-only
   // auto cap5 = [&a, b](auto first, auto second) { a = 78; b = 79; }; // error, b is read-only
   auto cap6 = [&a, &b](auto first, auto second) { a = 78; b = 79; }; // ok, a and b changed successfully
   cap6(a, b);
   std::cout << "a, b: " << a << ", " << b << std::endl; 

   std::cout << "Execute sum(3, 8) immediately upon definition POG: " << [](auto a, auto b){ return a + b; }(3, 8) << std::endl;
   {}
   {{{((([](){ [](){{{{}}}}(); }())));}}} // how the shit is this legal?!
}

int main()
{
   //cpp17_POGGERS();
   // lambdas();
   types();
   return 0;
}