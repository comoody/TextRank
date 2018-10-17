#include "TestSuite.h"

namespace test
{

TestSuite::TestSuite(std::string name):
    suiteName(name),
    tests(),
    testReporter()
{}

void TestSuite::assertEqual(const std::string& a, const std::string& b)
{
    if(a != b)
        throw FailedTestException("expected " + a + " to be equal to " + b);
}

TestSuite::Summary TestSuite::runTests()
{
    testReporter.displayLine("\n\n********* Running " + suiteName + " *********\n",
        TestReporter::TextColor::BLUE_TC, TestReporter::BackgroundColor::WHITE_BC, true /*bold*/);
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

        testReporter.displayLine(message, passed ? TestReporter::TextColor::DEFAULT_TC : TestReporter::TextColor::RED_TC);
        passed ? testSummary.passedCount++ : testSummary.failedCount++;
    }

    std::cout << suiteName + " done" << std::endl;
    testReporter.displayLine(std::to_string(testSummary.passedCount) + " passed",
        testSummary.passedCount > 0 ? TestReporter::TextColor::GREEN_TC : TestReporter::TextColor::DEFAULT_TC);
    testReporter.displayLine(std::to_string(testSummary.failedCount) + " failed",
        testSummary.failedCount > 0 ? TestReporter::TextColor::RED_TC : TestReporter::TextColor::DEFAULT_TC);

    return testSummary;
}

void TestSuite::assert(bool val)
{
    if(!val)
        throw FailedTestException("expected true");
}

}
