#ifndef UTILSTEST_H_
#define UTILSTEST_H_

#include <algorithm>

#include "./TestSuite.h"
#include "../src/utils.h"

namespace test
{

class UtilsTest final: public TestSuite
{
public:
    UtilsTest();
private:
    void stringSplitTest();
    void removeDuplicatesTest();
};

}

#endif