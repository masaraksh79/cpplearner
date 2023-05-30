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

#if 1 /* 3-5-4 */
   std::cout << "Please enter your Full name:";
   std::getline(std::cin, name);

   // Printing initials
   std::cout << "You initials are (" << name.substr(0, 1);
   int pos = name.find(" ");
   if (pos == std::string::npos)
   {
      std::cout << "Your full name is of illegal format!\n";
      return 1;
   }
   std::cout << ' ' << name.substr(pos+1, 1) << ')' << std::endl;
   
   // Printing the last name,first name
   int len = name.length();
   assert(pos > 0);
   std::cout << "You full name is " << name.substr(pos+1, len-pos+1) 
             << "," << name.substr(0, pos) << std::endl;
#endif

    return 0;
}
