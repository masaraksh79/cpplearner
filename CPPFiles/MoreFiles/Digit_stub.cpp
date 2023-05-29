/*
 *  Digit.cpp
 *      Stub for overloaded increment operators exercise.
 */
#include <iostream>

class Digit
{
public:
    Digit(int nDigit=0)
    {
        digit = nDigit;
    }

    Digit operator++();         // prefix
    Digit operator++(int);      // postfix

    Digit operator--();         // prefix
    Digit operator--(int);      // postfix

    bool operator==(int value);
    bool operator!=(int value);

    int getDigit() const { return digit; }

    operator int() { return digit; }

private:
    int digit;
};

std::ostream& operator<<(std::ostream& out, Digit d)
{
    out << int(d);
    return out;
}

bool Digit::operator==(int value)
{
   return (digit == value);
}

bool Digit::operator!=(int value)
{
   return (digit != value);
}

Digit Digit::operator++()
{
   digit++;
   if (digit > 9) digit = 0;
   return *this;
}

Digit Digit::operator++(int)
{
   Digit nd{digit};
   digit++;
   if (digit > 9) digit = 0;
   return nd;
}

Digit Digit::operator--()
{
   digit--;
   if (digit < 0) digit = 9;
   return *this;
}

Digit Digit::operator--(int)
{
   Digit nd{digit};
   digit--;
   if (digit < 0) digit = 9;
   return nd;
}

int main()
{
    Digit d = 7;        // Implicit constructor call

    std::cout << d;     // Print 7
    std::cout << ++d;   // Print 8
    std::cout << d++;   // Print 8
    std::cout << d;     // Print 9
    ++d;
    std::cout << d;     // Print 0

    Digit nine = 9;
    std::cout << nine++;    // 9
    std::cout << nine;      // 0

    nine = 1;

    std::cout << --nine;    // 0
    std::cout << nine--;    // 0
    std::cout << nine;      // 9


    Digit d2 = 9;
    if (d2 == 8) std::cout << "Digit is different from 8!";
    if (d2 != 9) std::cout << "Digit is the same as 9!";
    std::cout << "\n Int digit: " << int(d2) << std::endl;

    return 0;
}
