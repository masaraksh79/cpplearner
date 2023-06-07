/*
 *	sign.cpp
 *	Stub program for students to complete
 */
#include <iostream>

namespace utils
{
   template <typename T>
   int sign(T val)
   {
      return val >= 0 ? 1 : -1;
   }
}

int main()
{
	std::cout << "The sign of -5 is " << utils::sign(-5) << '\n';
	std::cout << "The sign of 4.5 is " << utils::sign(4.5) << '\n';
	std::cout << "The sign of 0 is " << utils::sign(0) << '\n';

	return 0;
}
