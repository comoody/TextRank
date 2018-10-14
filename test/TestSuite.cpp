#include "TestSuite.h"

using namespace test;

TestSuite::TestSuite(std::string name):
    suiteName(name),
    tests()
{}

TestSuite::Summary TestSuite::runTests()
{
    std::cout << "********* Running " << suiteName << "*********\n";
    Summary testSummary;

    for(auto testPair : tests)
    {
        int passed = false;
        std::string message;
        std::string testName = testPair.first;
        TestCallback testCallback = testPair.second;

        try
        {
            (this->*testCallback)();
            passed = true;
            message = testName + " passed";
        }
        catch(FailedTestException e)
        {
            message = testName + " failed: " + e.what();
        }
        catch(std::exception e)
        {
            message = "there was a problem runnung "
            + testName
            + ": "
            + e.what();
        }

        std::cout << message << std::endl;
        passed ? testSummary.passedCount++ : testSummary.failedCount++;
    }

    std::cout << suiteName + " done" << std::endl;
    std::cout << testSummary.passedCount << " passed" << std::endl;
    std::cout << testSummary.failedCount << " failed" << std::endl;

    return testSummary;
}

void TestSuite::registerTest(std::string description, TestCallback test)
{
    tests.push_back(std::pair<std::string, TestCallback>(description, test));
}

void assert(bool val)
{
    if(!val)
        throw FailedTestException("expected true");
}
