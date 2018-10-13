#include "./utils.h"

std::vector<std::string> textrank::stringSplit(const std::string& str, char delimeter)
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