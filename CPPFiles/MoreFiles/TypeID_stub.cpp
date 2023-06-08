/*
 *  TypeID_stub.cpp
 *      Stub for typeid exercises.
 */
#include <iostream>
#include <typeinfo>
#include <string>

using std::cout;
using std::endl;

class MyClass{ private: int i; public: MyClass():i{0}{}};

// ------------------------------------
int main()
{
    bool b;
    char c;
    short sh;
    int i;
    long l;
    float f;
    double d;
    std::string s;

    cout << "b=" << typeid(b).name() << '\n';
    cout << "c=" << typeid(c).name() << '\n';
    cout << "sh=" << typeid(sh).name() << '\n';
    cout << "i=" << typeid(i).name() << '\n';
    cout << "l=" << typeid(l).name() << '\n';
    cout << "f=" << typeid(f).name() << '\n';
    cout << "d=" << typeid(d).name() << '\n';
    cout << "myClass=" << typeid(MyClass).name() << '\n';
    cout << "s=" << typeid(s).name() << endl;

    return 0;
}
