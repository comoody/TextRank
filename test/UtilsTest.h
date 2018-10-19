#ifndef UTILSTEST_H_
#define UTILSTEST_H_

#include "./TestSuite.h"

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