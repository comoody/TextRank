#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include <exception>
#include <iostream>
#include <string>
#include <type_traits>
#include <vector>

#include "./FailedTestException.h"
#include "./TestReporter.h"

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
    
    // template that can only be instantiated by derived classes
    // equivalent to template<T extends TestSuite>
    // thus, derived classes pass in their member pointers and safely be casted as TestSuite (base) methods
    // because the base instance on which the methods will be called will always be an instance of derived class T
    template<typename T, typename std::enable_if<std::is_base_of<TestSuite, T>::value>::type* = nullptr>
    void registerTest(std::string description, void(T::*derivedTestCallback)())
    {
        auto testCallback = static_cast<TestCallback>(derivedTestCallback);
        tests.push_back(std::pair<std::string, TestCallback>(description, testCallback));
    }

    void assert(bool val);

    template<typename T>
    void assertEqual(T a, T b)
    {
        if(a != b)
            throw FailedTestException("expected " + std::to_string(a) + " to be equal to " + std::to_string(b));
    }

    // assert equal is overloaded for strings because std::to_string from the generic version does not work on strings
    void assertEqual(const std::string& a, const std::string& b);

    void displayLine(std::string message);

private:
    std::string suiteName;
    std::vector<std::pair<std::string, TestCallback>> tests;
    TestReporter testReporter;
};

}

#endif