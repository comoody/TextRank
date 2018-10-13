#include "./FailedTestException.h"

using namespace test;

FailedTestException::FailedTestException(const char* reason):
    reason(reason)
{}

const char* FailedTestException::what()
{
    return reason;
}