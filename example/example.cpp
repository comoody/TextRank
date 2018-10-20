#include <fstream>
#include <iostream>

#include "../src/utils.h"
#include "../include/TextRanker.h"

int main()
{
    std::ifstream textFile;
    textFile.open("./example.txt");
    std::string text((std::istreambuf_iterator<char>(textFile)), std::istreambuf_iterator<char>());

    auto sentences = textrank::extractSentences(text);

    textrank::TextRanker ranker;
    auto results = ranker.rank(sentences);

    // write top 10 sentences from results
    int count = 1;
    for(std::vector<std::string>::iterator i = results.begin(); i < results.begin() + 10; i++)
    {
        std::cout << "\n\n\n" << count++ << ")\n";
        std::cout << *i << std::endl;
    }

    textFile.close();
}