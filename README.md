## TextRank Algorithm

This project implements the TextRank algorithm on a set of text. The goal of the TextRank algorithm is to rank sentences in the order that best represents the body of text. This implementation of TextRank is outlined by the following steps:

1. Split the text into sentences.
2. Construct an adjacency matrix representing a graph where each sentence has every other sentence as a neighbor
3. Fill in the adjacency Matrix by measuring the similiarity between each sentence
    - The similiarty function uses number of words in common and closeness in length to output a similarity measure
4. Execute a given number of walks which traverse the similarity matrix
    - A walk begins at a random sentence
    - The sentence is marked as visited
    - Using the similarities between the sentence and each of its neighbors as a probability distribution, a neighbor is randomly selected as the next candidate for a visit
    - A random number determines the continuation of the walk with a probability of beta (~.9) that the walk will continue
        - if the walk continues, the next visit will be to the previously chosen neighbor candidate
        - if the walk does not continue, the next visit will be to a random sentence

5. Rank the sentences by the number of visits they received during the series of walks
    - sentences which were visited more by their neighbors should be very similar to a large number of sentences and should be representative of the body of text

## API
The *TextRanker* class contains all of the logic implementing the TextRank algorithm.  
*TextRanker::Rank(std::vector\<std::string> sentences)* runs the entire algorithm on a vector of sentences  

  
## Tests
Tests are found in the test/ directory. Test classes inherit from *TestSuite* and define tests as private member functions. To ensure that these tests run, test classes call *registerTest(name, testFunc)* and pass it a test name as well as a pointer to the member function that includes the test case. Tests can call *assert(condition)* as well as *assertEqual(a, b)* to execute test logic. Results are reported using the *TestReporter* class.

From test/, calling *make* will create a file called testbench in bin/. Running testbench will run the entire test suite.

