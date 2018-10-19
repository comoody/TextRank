#ifndef UTILS_H_
#define UTILS_H_

#include <unordered_set>
#include <vector>

namespace textrank
{

// removes duplicates from a vector and does not preserve order
template<typename T>
std::vector<T> removeDuplicates(const std::vector<T>& vec)
{
    std::unordered_set<T> set;
    for(T val : vec)
        set.insert(val);
    
    std::vector<T> uniqueVec;
    for(T val : set)
        uniqueVec.push_back(val);    
    return uniqueVec;
}

std::vector<std::string> stringSplit(const std::string& str, char delimeter);

}

#endif