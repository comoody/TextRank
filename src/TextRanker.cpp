#include "../include/TextRanker.h"

#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <set>

#include "../src/utils.h"

using namespace textrank;

TextRank::TextRank():
    kNewWalkThreshold(0.85)
{
    srand(time(0));
}

TextRank::~TextRank() {}

std::vector<std::string> TextRank::rank(const std::vector<std::string>& sentences) const
{
    std::vector<std::string> uniqueSentences = removeDuplicates(sentences);
    FloatMatrix similarityMatrix = buildSimilarityMatrix(uniqueSentences);
    // run textrank algorithm and return results
    return rankSentences(similarityMatrix, uniqueSentences);
}

TextRank::FloatMatrix TextRank::buildSimilarityMatrix(const std::vector<std::string>& sentences) const
{
    const int kDim = sentences.size();
    std::vector<std::vector<float>> similarityMatrix(kDim, std::vector<float>(kDim, 0));
    for(int i = 0; i < kDim - 1; i++)
    {
        for(int j = i + 1; j < kDim; j++)
        {
            float similarity = getSimilarity(sentences[i], sentences[j]);
            // the similarity matrix is symmetrical, so transposes are filled in with the same similarity
            similarityMatrix[i][j] = similarity;
            similarityMatrix[j][i] = similarity;
        }
    }
    return similarityMatrix;
}

std::vector<std::string> TextRank::rankSentences
(
    const TextRank::FloatMatrix& similarityMatrix,
    const std::vector<std::string>& sentences
) const
{
    // initializes score map
    std::map<std::string, int> visits;
    for(std::string sentence : sentences)
        visits[sentence] = 0;
    
    const int kWalkCount = 20;
    const int kDim = sentences.size();

    for(int i = 0; i < kWalkCount; i++)
        doSentenceGraphWalk(similarityMatrix, sentences, visits);
    
    // after the walks have been completed, rank the sentences according to their number of visits
    typedef std::pair<std::string, int> VisitPair;
    std::vector<VisitPair> visitPairs;
    for(auto visitPair : visits)
        visitPairs.push_back(visitPair);
    std::sort(visitPairs.begin(), visitPairs.end(), [](VisitPair a, VisitPair b) { return a.second < b.second; });

    std::vector<std::string> rankedSentences;
    std::transform(visitPairs.begin(), visitPairs.end(), rankedSentences.begin(), [](VisitPair visitPair) { return visitPair.first; });
    
    return rankedSentences;
}

// does a single walk that visits sentences around the graph according to probabilities defined in the similarity matrix
// after each iteration inside the walk, there is a 1 - kNewWalkThreshold probability that the walk will end and this
// method will return
// during the walk, the visits map is updated accoridingly
void TextRank::doSentenceGraphWalk
(
    const FloatMatrix& similarityMatrix,
    const std::vector<std::string>& sentences,
    std::map<std::string, int>& visits
) const
{
    const int kDim = sentences.size();
    bool continueWalk = true;
    // start walk at a random node in the sentence graph
    int curSentenceIndex = rand() % kDim;
    while (continueWalk)
    {
        // visit the curSentence
        std::string curSentence = sentences[curSentenceIndex];
        visits[curSentence]++;

        // the row of the similarity matrix corresponding to the current sentence represents the probabilites
        // of transferring to all ofther sentences from the current sentence
        std::vector<float> probabilites = similarityMatrix[curSentenceIndex];

        // normalize probabilites
        float sum = std::accumulate(probabilites.begin(), probabilites.end(), 0.f);
        std::transform(probabilites.begin(), probabilites.end(), std::back_inserter(probabilites), [sum](float probability)
        {
            return probability / sum;
        });

        // stack probabilites
        std::vector<float> probabilityDistribution;
        for(std::vector<float>::iterator j = probabilites.begin(); j < probabilites.end(); j++)
            probabilityDistribution.push_back(std::accumulate(probabilites.begin(), j, 0.f));
        
        // get a random number betweeon 0 and 1
        float selector = rand() % 1000 / 1000;

        int selectedIndex = 0;
        while(selector < probabilityDistribution[selectedIndex])
            selectedIndex++;
        
        // update the curSentence index so that it can be visited in the next iter of the current walk
        curSentenceIndex = selectedIndex;

        // randomly test for the end of a walk, if the random number is above kNkNewWalkThreshold, start a new walk
        float newWalkSelector = rand() % 1000 / 1000;
        if(newWalkSelector > kNewWalkThreshold)
            continueWalk = false;
    }
}

float TextRank::getSimilarity(std::string a, std::string b) const
{
    // no two equivalent sentences should ever be compared, but this logic is included just in case
    if(a == b)
        return 0.f;

    std::transform(a.begin(), a.end(), a.begin(), ::tolower);
    std::vector<std::string> aWords = stringSplit(a, ' ');  
    std::set<std::string> aWordSet;
    for(auto word : aWords)
        aWordSet.insert(word);

    std::transform(b.begin(), b.end(), b.begin(), ::tolower);
    std::vector<std::string> bWords = stringSplit(b, ' ');
    std::set<std::string> bWordSet;
    for(auto word : bWords)
        bWordSet.insert(word);

    std::vector<std::string> commonWords;
    std::set_intersection
    (
        aWordSet.begin(),
        aWordSet.end(),
        bWordSet.begin(),
        bWordSet.end(),
        std::back_inserter(commonWords)
    );

    int commonWordCount = commonWords.size();
    
}

