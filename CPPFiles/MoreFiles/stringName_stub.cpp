/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>

int main()
{
   std::string name;

#if 0 /* 3-5-2 */
   std::cout << "Please enter your name:";
   //std::cin >> name;
   std::getline(std::cin, name);
   if (name == "Yakir" || name == "yakir")
      std::cout << "Welcome!" << std::endl;
   else
      std::cout << "Wrong name!" << std::endl;
#endif

#if 0 /* 3-5-3 */
   std::cout << "Please enter your name:";
   std::getline(std::cin, name);
   std::cout << name.substr(0, 1) << std::endl;
#endif

#if 0 /* 3-5-4 */
   std::cout << "Please enter your Full name:";
   std::getline(std::cin, name);
   std::cout << name.substr(0, 1);
   int pos = name.find(" ");
   if (pos == std::string::npos)
   {
      std::cout << "Your full name is of illegal format!\n";
      return 1;
   }
   std::cout << ' ' << name.substr(pos+1, 1) << std::endl;
   
#endif

    return 0;
}
