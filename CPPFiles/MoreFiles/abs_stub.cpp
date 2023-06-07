/*
 *	abs.cpp
 *	Stub program for students to complete.
 */
#include <iostream>

namespace utils
{
   template <typename T>
   T abs(T inp)
   {
      return inp < 0 ? -inp : inp;
   }
}

int main()
{
   using namespace utils;

	std::cout << "abs(-5) is " << abs(-5) << '\n';
	std::cout << "abs(-4.5) is " << abs(4.5) << '\n';
	std::cout << "abs(5) is " << abs(5) << '\n';

	return 0;
}
