#include "./UtilsTest.h"

#include <algorithm>

#include "../src/utils.h"

using namespace test;

UtilsTest::UtilsTest():
    TestSuite("utils tests")
{
    registerTest("test string split functionality", &UtilsTest::stringSplitTest);
    registerTest("test remove duplicates functionality", &UtilsTest::removeDuplicatesTest);
}

void UtilsTest::stringSplitTest()
{
    auto str = "    one two  three    four";
    std::vector<std::string> splitStrs = textrank::stringSplit(str, ' ');
    
    assertEqual(static_cast<int>(splitStrs.size()), 4);
    assertEqual(splitStrs[0], std::string("one"));
    assertEqual(splitStrs[1], std::string("two"));
    assertEqual(splitStrs[2], std::string("three"));
    assertEqual(splitStrs[3], std::string("four"));
}

void UtilsTest::removeDuplicatesTest()
{
    // string test
    std::vector<std::string> strings = {"one", "one", "two", "three"};
    auto resultStrs = textrank::removeDuplicates(strings);

    assertEqual(static_cast<int>(resultStrs.size()), 3);
    assert(std::find(resultStrs.begin(), resultStrs.end(), "one") != resultStrs.end());
    assert(std::find(resultStrs.begin(), resultStrs.end(), "two") != resultStrs.end());
    assert(std::find(resultStrs.begin(), resultStrs.end(), "three") != resultStrs.end());


    std::vector<int> nums = {1, 1, 2, 3};
    auto resultNums = textrank::removeDuplicates(nums);

    assertEqual(static_cast<int>(resultNums.size()), 3);
    assert(std::find(resultNums.begin(), resultNums.end(), 1) != resultNums.end());
    assert(std::find(resultNums.begin(), resultNums.end(), 2) != resultNums.end());
    assert(std::find(resultNums.begin(), resultNums.end(), 3) != resultNums.end());
}