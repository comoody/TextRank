#include "./utils.h"

#include <algorithm>
#include <sstream>

namespace textrank
{

std::vector<std::string> stringSplit(const std::string& str, char delimeter)
{

    std::vector<std::string> results;
    
    std::stringstream ss;
    for(char character : str)
    {
        if(character == delimeter)
        {
            std::string splitStr = ss.str();
            ss.str(std::string()); // clear out stringstream
            if(splitStr.length() > 0)
                results.push_back(splitStr);
        }
        else
        {
            ss << character;
        }
    }

    if(ss.str().length() > 0)
        results.push_back(ss.str());

    return results;    
}

static std::vector<char> punctuation { '.', '!', '?' };

static std::vector<std::string> abbreviations
{
    "Mr",
    "Ms",
    "Mrs",
    "Dr"
};

static bool isPunctuation(char c)
{
    return std::find(punctuation.begin(), punctuation.end(), c) != punctuation.end();
}

static bool isAbbreviationPeriod()
{

}

std::vector<std::string> extractSentences(const std::string& str)
{
    // TEMP switch out all punctuation for periods
    std::stringstream ss;
    for(int i = 0; i < str.length(); i++)
    {
        if(isPunctuation(str[i] && str[i] != '.'))
            ss << '.';
        else
            ss << str[i];
    }

    return stringSplit(ss.str(), '.');
}

}