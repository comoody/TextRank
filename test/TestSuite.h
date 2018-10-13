#ifndef TESTSUITE_H_
#define TESTSUITE_H_

#include <exception>
#include <iostream>
#include <string>
#include <vector>

#include "./FailedTestException.h"

namespace test
{

// base class to register and run tests
class TestSuite
{
public:
    TestSuite(std::string suiteName);
    ~TestSuite();

    struct Summary
    {
        int passedCount;
        int failedcount;
    };

    Summary runTests();

protected:
    typedef void (TestSuite::*TestCallback)();
    void registerTest(std::string description, TestCallback test);

private:
    std::string suiteName;
    std::vector<std::pair<std::string, TestCallback>> tests;
};

}

#endif