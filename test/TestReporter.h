#ifndef TESTREPORTER_H_
#define TESTREPORTER_H_

#include <string>

namespace test
{

class TestReporter
{
public:
    TestReporter();

    enum TextColor
    {
        RED_TC = 31,
        GREEN_TC = 32,
        BLUE_TC = 34,
        DEFAULT_TC  = 39
    };

    enum BackgroundColor
    {
        RED_BC = 41,
        GREEN_BC = 42,
        BLUE_BC = 44,
        WHITE_BC = 47,
        DEFAULT_BC = 49    
    };

    void displayLine
    (
        const std::string& message,
        TextColor textColor = TextColor::DEFAULT_TC,
        BackgroundColor backgroundColor = BackgroundColor::DEFAULT_BC,
        bool isBold = false
    ) const;

private:
    bool isColorSupported;
};

}

#endif