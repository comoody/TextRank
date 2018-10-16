#ifndef FAILEDTESTEXCEPTION_H_
#define FAILEDTESTEXCEPTION_H_

#include <exception>
#include <string>

namespace test
{

class FailedTestException: public std::exception
{
public:
    FailedTestException(const std::string& reason);
    virtual const char* what() const noexcept;

private:
    std::string reason;
};

}

#endif