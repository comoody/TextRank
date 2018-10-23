#ifndef TEXTRANKER_H_
#define TEXTRANKER_H_

#include <map>
#include <string>
#include <vector>

namespace test
{
    class TextRankerTest;
}

namespace textrank
{

class TextRanker
{
public:
    TextRanker();
    ~TextRanker();

    std::vector<std::string> rank(const std::vector<std::string>& sentences) const;
private:
    friend class test::TextRankerTest;
    typedef std::vector<std::vector<float>> FloatMatrix; 

    const float kNewWalkThreshold;

    float getSimilarity(std::string a, std::string b) const;
    FloatMatrix buildSimilarityMatrix(const std::vector<std::string>& sentences) const;
    std::vector<std::string> rankSentences(const FloatMatrix& similarityMatrix, const std::vector<std::string>& sentences) const;
    void doSentenceGraphWalk
    (
        const FloatMatrix& similarityMatrix,
        const std::vector<std::string>& sentences,
        std::map<std::string, int>& visits
    ) const;
};

}

#endif