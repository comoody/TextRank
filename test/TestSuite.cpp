#include "TestSuite.h"

namespace test
{

TestSuite::TestSuite(std::string name):
    suiteName(name),
    tests()
{}

void TestSuite::assertEqual(const std::string& a, const std::string& b)
{
    if(a != b)
        throw FailedTestException("expected " + a + " to be equal to " + b);
}

TestSuite::Summary TestSuite::runTests()
{
    std::cout << "\n\n********* Running " << suiteName << "*********\n\n";
    Summary testSummary;
    testSummary.passedCount = 0;
    testSummary.failedCount = 0;

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
        catch(const FailedTestException& e)
        {            
            message = testName + " failed: " + std::string(e.what());
        }
        catch(const std::exception& e)
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

void TestSuite::assert(bool val)
{
    if(!val)
        throw FailedTestException("expected true");
}

}
