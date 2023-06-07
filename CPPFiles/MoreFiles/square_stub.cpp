/*
 *	square.cpp
 *	Stub program for students to complete
 */
#include <iostream>

template <typename T>
T square(T num)
{
   return num * num;
}

int main()
{
    // This will call square(int)
    std::cout << "Answer is " << square(2) << '\n';

    // This will call square(double)
    std::cout << "Answer is " << square(2.1) << '\n';

    return 0;
}
