#include <iostream>

#include <fraction.hpp>

int main()
 {
  fraction a(4,3);
  fraction b(5,4);

  std::cout 
   << "a=" << a << std::endl
   << "b=" << b << std::endl
   << "~a=" << ~a << std::endl
   << "~b=" << ~b << std::endl
   << "4+a=" << 4+a << std::endl
   << "a+4=" << a+4 << std::endl
   << "4-a=" << 4-a << std::endl
   << "a-4=" << a-4 << std::endl
   << "a+b=" << a+b << std::endl
   << "a-b=" << a-b << std::endl
   << "a*b=" << a*b << std::endl
   << "a*3=" << a*3 << std::endl
   << "11*a=" << 11*a << std::endl
   << "a/b=" << a/b << std::endl
   << "7/a=" << 7/a << std::endl
   << "a/9=" << a/9 << std::endl
   ;

  // 3/7
  std::cout << fraction(3,4)*fraction(4,5)*fraction(5,6)*fraction(6,7) << std::endl;
  return 0;
 }
