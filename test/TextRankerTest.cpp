#include "./TextRankerTest.h"
#include "../include/TextRanker.h"

#include <vector>

using namespace test;

TextRankerTest::TextRankerTest():
    TestSuite("text ranker test")
{
    registerTest("text rank integration test", &TextRankerTest::textRankIntegrationTest);
    registerTest("build similarity matrix test", &TextRankerTest::buildSimilarityMatrixTest);
}

// tests that no exceptions are thrown during full textrank execution
void TextRankerTest::textRankIntegrationTest()
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

// tests that the resulting similarity matrix:
//  1) has the correct dimensions
//  2_ is symmetric
void TextRankerTest::buildSimilarityMatrixTest()
{
    textrank::TextRanker ranker;

    std::vector<std::string> sentences =
    {
        "sentence one",
        "sentence two",
        "sentence three"
    };

    textrank::TextRanker::FloatMatrix similarityMatrix = ranker.buildSimilarityMatrix(sentences);

    // test dimensionality
    assertEqual(similarityMatrix.size(), sentences.size());
    for(int i = 0; i < similarityMatrix.size(); i++)
    {
        assertEqual(similarityMatrix[i].size(), sentences.size());
    }

    // test symmetry
    for(int i = 0; i < sentences.size(); i++)
    {
        for(int j = 0; j <= i; j++)
        {
            if(i == j)
                assertEqual(similarityMatrix[i][j], 0.f);
            else
                assertEqual(similarityMatrix[i][j], similarityMatrix[j][i]);
        }
    }
}
