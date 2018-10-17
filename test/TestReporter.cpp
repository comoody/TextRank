#include "./TestReporter.h"

using namespace test;

TestReporter::TestReporter()
{
    std::string terminalName = std::string(::getenv("TERM"));
    isColorSupported = true;
}

void TestReporter::displayLine
(
    std::string message,
    TextColor textColor,
    BackgroundColor backgroundColor,
    bool isBold
) const
{
    int boldCode = isBold ? 1 : 0;
    if(isColorSupported)
    {
        std::cout << "\033[" << isBold << ";" << textColor << ";" << backgroundColor << "m"
            << message << "\033[0m" << std::endl;
    }
    else
    {
        std::cout << message << std::endl;
    }
}