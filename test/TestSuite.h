#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "./FailedTestException.h"

namespace test
{

// abstract base class to register and run tests
class TestSuite
{
public:
    struct Summary
    {
        int passedCount;
        int failedCount;
    };

    Summary runTests();

protected:
    TestSuite(std::string suiteName);

    typedef void (TestSuite::*TestCallback)();
    void registerTest(std::string description, TestCallback test);

    void assert(bool val);

    template<typename T>
    void assertEqual(T a, T b)
    {
        if(a != b)
            throw FailedTestException("expected " + std::to_string(a) + " to be equal to " + std::to_string(b));
    }

private:
    std::string suiteName;
    std::vector<std::pair<std::string, TestCallback>> tests;
};

}

#endif