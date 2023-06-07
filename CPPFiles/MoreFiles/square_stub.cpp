/*
 *	square.cpp
 *	Stub program for students to complete
 */
#include <iostream>

using std::cout;

namespace utils
{
   template <typename T>
   T square(T num)
   {
      return num * num;
   }
}

int main()
{
   // This will call square(int)
   cout << "Answer is " << utils::square(2) << '\n';

   // This will call square(double)
   cout << "Answer is " << utils::square(2.1) << '\n';

   return 0;
}
