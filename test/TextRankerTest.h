#ifndef TEXTRANKERTEST_H_
#define TEXTRANKERTEST_H_

#include "./TestSuite.h"

namespace test
{

class TextRankerTest final: public TestSuite
{
public:
    TextRankerTest();
private:
    void rankIntegrationTest();
};

};

#endif