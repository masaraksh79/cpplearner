/*
 * Stub for working with strings exercise.
*/
#include <iostream>
#include <string>
#include <array>

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
   auto pos = name.find(" ");
   if (pos == std::string::npos)
   {
      std::cout << "Your full name is of illegal format!\n";
      return 1;
   }
   std::cout << ' ' << name.substr(pos+1, 1) << ')' << std::endl;
   
   // Printing the last name,first name
   auto len = name.length();
   assert(pos > 0);
   std::cout << "You full name is " << name.substr(pos+1, len-pos+1) 
             << "," << name.substr(0, pos) << std::endl;
#endif

#if 0 /* 3-5-5 */
   const int numNames = 5;
   int nextpos = 0;
   std::array<std::string,numNames> names;
   std::string inp;
   std::cout << "Please enter exactly five names:";
   std::getline(std::cin, inp);

   for (int i = 0; i < numNames; i++)
   {
      if (std::string::npos != (nextpos = inp.find(" ")))
      {
         names[0] = inp.substr(i, nextpos);
      }
      else
      {
         // could be final position with no space
         if (i == numNames - 1)
         {
            if (std::string::npos != (nextpos = inp.rfind(" ")))
               names[i] = inp.substr(nextpos+1, inp.length()-nextpos+1);
            else
               return 2;   
         }
         else
         {
            std::cout << "Could not find " << numNames << " names" << std::endl;
            return 1;
         }
      }
   }

   //Print the names
   for (int i = 0; i < numNames; i++)
      std::cout << i << ") " << names.at(i) << std::endl;


#endif
    return 0;
}
