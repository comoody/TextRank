#include "./FailedTestException.h"

using namespace test;

FailedTestException::FailedTestException(const std::string& reason):
    reason(reason)
{}

const char* FailedTestException::what() const noexcept
{
    return reason.c_str();
}