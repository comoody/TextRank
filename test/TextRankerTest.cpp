#include "./TextRankerTest.h"
#include "../include/TextRanker.h"

#include <vector>

using namespace test;

TextRankerTest::TextRankerTest():
    TestSuite("text ranker test")
{
    registerTest("text rank integration test", &TextRankerTest::rankIntegrationTest);
}

void TextRankerTest::rankIntegrationTest()
{
    textrank::TextRanker ranker;
    std::vector<std::string> sentences
    {
        "a sentence about spaghetti",
        "another sentence with spaghetti in it",
        "blah blah blah",
        "a sentence about nothing"
    };
    auto results = ranker.rank(sentences);
    assertEqual((int)results.size(), 4);
}