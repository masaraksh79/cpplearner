/*
Test program to check that Boost test is installed and ready to go.
Should work with any version of Boost Test. Actual output will vary.

This program (probably) needs to be compiled with -I/boost/include/boost-1_77
or similar.
*/
#define BOOST_TEST_MODULE Peters Test
#include <iostream>
#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(PetersTestCase)
{
    int i = 2;

    std::cout << "BOOST_VERSION     " << BOOST_VERSION << '\n';         // 1077001
    std::cout << "BOOST_LIB_VERSION " << BOOST_LIB_VERSION << '\n';     // 1_77

    BOOST_CHECK_EQUAL(i, 3);                    // Should pass
}

// End of program
