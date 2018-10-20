#include "./UtilsTest.h"
#include "./TextRankerTest.h"

int main()
{
    test::UtilsTest utilsTest;
    utilsTest.runTests();

    test::TextRankerTest textRankerTest;
    textRankerTest.runTests();

    return 0;
}