#ifndef FAILEDTESTEXCEPTION_H_
#define FAILEDTESTEXCEPTION_H_

#include <exception>

namespace test
{

class FailedTestException: public std::exception
{
public:
    FailedTestException(const char* reason);
    virtual const char* what();

private:
    const char* reason;
};

}

#endif