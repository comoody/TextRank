#include "./TestReporter.h"

#include <iostream>

using namespace test;

TestReporter::TestReporter()
{
    std::string terminalName = std::string(::getenv("TERM"));
    isColorSupported = terminalName.find("color") != std::string::npos;
}

void TestReporter::displayLine
(
    const std::string& message,
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