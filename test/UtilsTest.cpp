#include "./UtilsTest.h"

using namespace test;

UtilsTest::UtilsTest():
    TestSuite("utils tests")
{
    registerTest("test string split functionality", &UtilsTest::stringSplitTest);
    registerTest("test remove duplicates functionality", &UtilsTest::removeDuplicatesTest);
}

void UtilsTest::stringSplitTest()
{
    return;
}

void UtilsTest::removeDuplicatesTest()
{
    return;
}