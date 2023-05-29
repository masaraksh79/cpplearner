// C++ Course
// Exercise 1

#include <iostream>
#include <string>
#include <cassert>
#include <stdexcept>

// Exercise 1 Pre-requisite
struct HelloWorld {
    HelloWorld() {
        std::cout << "Hello World!!!" << std::endl;
    }
};

// Exercise 2 Pre-requisite
class NauticalMiles {
private:
    double conversionFactor;
    unsigned int numberOfConversions;
    double initialValue = 1.0;          // implicitly starting at 1 mile
    double mileGap = 1.0;               // also implicitly jump by 1
public:
    NauticalMiles(double f, unsigned int c) : 
        conversionFactor{ 
         f }, numberOfConversions{ c } { }

    void nmTitlePrint(void) {
        std::cout << "Nautical Miles" << "\t\t" << "Kilometers" << std::endl;
    }
    double milesToKm(double in) { return conversionFactor * in; }
    void print(void);
};

void NauticalMiles::print(void) {
    double val = initialValue;
    nmTitlePrint();
    for (int i = 0; i < numberOfConversions; i++, val+=mileGap)
    {
        std::cout << val << "\t\t\t" << milesToKm(val) << std::endl;
    }
}

// Exercise 3 Pre-requisite
namespace Fibs {
    class FiboUtility {
    public:
        FiboUtility(uint16_t maxFiboNumber) : fibMax{ maxFiboNumber } { 
            fibSum = 0; cnt = 0;
            while (true)
            {
                if (fibMax <= (fibNum = fiboSumGen()))
                    break;

                fibSum += fibNum;
                ++cnt;
            }

            fibSum += 1;    /* add 1st number due to nature of initalization */
        }
        uint16_t fiboSumGen(void) noexcept;
        uint16_t getFibSum(void) noexcept { return fibSum; }
    private:
        uint16_t cnt, fibSum, fibMax, fibNum = 0, f1 = 0, f2 = 1;
    };

    /* function */
    uint16_t FiboUtility::fiboSumGen(void) noexcept {
        uint16_t res = f1 + f2;
        f1 = f2;
        f2 = res;
        return res;
    }
}

// Exercise 4 Main task
double average(double *values)
{
    double sum = 0.0;
    int s = 0;
    
    while (values[s] != 0)
    {
        sum += values[s++];
    }

    assert(s != 0);
    return (sum / (double)s);
}

// Exercise 5 Main task (complete the class)
class Dot
{
private:
    int X, Y;
    bool dot;
public:
    Dot() { dot = false; X = 0; Y = 0; }
    int getX(void) { return X; }
    int getY(void) { return Y; }
    void setOn(void) { dot = true; }
    bool isItOn(void) { return dot; }
    void position(int x, int y) {
        X = x;
        Y = y;
    }
};

int main()
{
    // Exercise 1

    HelloWorld hw;

    // Exercise 2

    NauticalMiles nm(1.852, 20);
    nm.print();

    // Exercise 3

    Fibs::FiboUtility fib((uint16_t)1000);
    std::cout << "Fibo sum is " << fib.getFibSum() << std::endl;

    // Exercise 4
    /* Taken from average_stub.cpp
     * Stub for the pre-course exercise
     */
    // 0 marks the end of the numbers to average
    // Don't include the zero in the average calculation
    double nums[] = { 3.3, 2.2, 5.5, 10.10, 0 };
    double answer;

    answer = average(nums);

    std::cout << "The average of these numbers is " << answer << std::endl;

    // Exercise 5
    /*
     *  dotincomplete.cpp
     *  Stub for the pre-course exercise
     */
    Dot corner;

    corner.setOn();
    corner.position(5, 10);

    if (corner.isItOn())
        std::cout << "The Dot is now On\n";     // Should print

    // Should print "The Dot is at 5 10"
    std::cout << "The Dot is at " << corner.getX() << ' ' << corner.getY() << '\n';
}
