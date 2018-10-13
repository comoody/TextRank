#ifndef TEXTRANKER_H_
#define TEXTRANKER_H_

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <map>
#include <numeric>
#include <set>
#include <string>
#include <vector>

#include "../src/utils.h"

namespace textrank
{

class TextRank
{
public:
    TextRank();
    ~TextRank();

    std::vector<std::string> rank(const std::vector<std::string>& sentences);
private:
    typedef std::vector<std::vector<float>> FloatMatrix; 

    const float kNewWalkThreshold;

    float getSimilarity(std::string a, std::string b);
    FloatMatrix buildSimilarityMatrix(const std::vector<std::string>& sentences);
    std::vector<std::string> rankSentences(const FloatMatrix& similarityMatrix, const std::vector<std::string>& sentences);
    void doSentenceGraphWalk
    (
        const FloatMatrix& similarityMatrix,
        const std::vector<std::string>& sentences,
        std::map<std::string, int>& visits
    );
};

}

#endif