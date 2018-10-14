#include "./UtilsTest.h"

using namespace test;

UtilsTest::UtilsTest():
    TestSuite("utils tests")
{
    registerTest("test string split functionality", static_cast<TestCallback>(&UtilsTest::stringSplitTest));
    registerTest("test remove duplicates functionality", static_cast<TestCallback>(&UtilsTest::removeDuplicatesTest));
}

void UtilsTest::stringSplitTest()
{
    return;
}

void UtilsTest::removeDuplicatesTest()
{
    return;
}