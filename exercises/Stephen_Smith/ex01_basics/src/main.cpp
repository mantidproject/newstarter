#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include "../include/splitLineIntoWords.h"

using WordCount = std::pair<std::string, int>;
namespace{
    constexpr int MIN_WORD_LENGTH=5;
	constexpr auto PUNCTUATION = ".!,\"?!";
}

  /**
   * Removes punctuation from an input word
   * @param iString Contains the input word, with the punctaution removed in place 
   */
int removePunctuation(std::string &iString)
{
	std::string::iterator itr = iString.begin();
	static const std::string punctuation(PUNCTUATION);

    while (itr != iString.end())
    {
        char c = *itr;
        if ( punctuation.find(c) != std::string::npos )
        {
            itr = iString.erase(itr);
        }else{
            ++itr;
        }
    }

    return 0;
}

// Function to compare counts of two words eached stored in std::pair with the associated count
// Input paramter = std::pair of <word,count>
  /**
   * Compares the counts of two words contained within the input parameters
   * @param wordCount_1 The word and associated count of the first pair
   * @param wordCount_1 The word and associated count of the second pair
   * @return A boolean which is true if wordCount_2 > wordCount_1
   */
bool compareWordCounts(WordCount wordCount_1, WordCount wordCount_2)
{
    return (wordCount_1.second > wordCount_2.second);
}


int main(int argc, char * argv[])
{
    // Initial variables
    std::ifstream file;
    bool fileopen = false;
	// Check number of arguments supplied is correct
    if ( argc < 2)
    {
        std::cout << "Error: No filename entered." << std::endl;
        return -1;
    }

    // Open file
    std::string input_filename(argv[1]);
    file.open(input_filename);
	// Check the file is correctly open
    if ( !file.is_open())
    {
        std::cout << "Error: Could not find input file." << std::endl;
        return -1;
    }

    // Map to store word, and asscoiated word count
    std::map<std::string,int> wordCounts;
    // Loop over each line of the file
    std::string line;
    // Process each line of the file
    while(getline(file,line))
    {
        std::vector<std::string> lineWords = splitLineIntoWords(line); 
        if (!lineWords.empty())
        {
            for (auto word : lineWords)
            {
                // make each word lower case
                std::transform(word.begin(),word.end(),word.begin(),::tolower);
                // remove punctuation
                removePunctuation(word);
                // count number of letters in word
                std::string::size_type word_length = word.length();           
                // add word of length (>= MIN_WORD_LENGTH) to map container ;
                if ( word_length >= MIN_WORD_LENGTH)
                {
                    // Add word and count to map
                    auto retPair = wordCounts.insert(std::make_pair(word,1));
                    // Test if the pair was added successfully to the map. 
                    if (retPair.second == false)
                    {
                        // element already existed, increment count
                        ++retPair.first->second;
                    }
                }
            }
        }
    }

    file.close();
    // Copy each <word,count> pair into a vector container
    std::vector<WordCount> sortedWordCount(wordCounts.size());
	std::copy(std::begin(wordCounts), std::end(wordCounts), std::begin(sortedWordCount));
    // Sort words by occurance using compare function
    std::sort(sortedWordCount.begin(),sortedWordCount.end(),compareWordCounts);
    // Output words into a file
    std::string output_filename = "sorted_" + input_filename ;
    std::ofstream outputfile(output_filename, std::ofstream::out);
    // ensure output file is open
    if (outputfile.is_open())
    {
        outputfile << std::setw(20) << "Word" << std::setw(20) << "count" << std::endl;
        for (const auto& wordAndCount : sortedWordCount)
        {
            outputfile << std::setw(20) << wordAndCount.first << std::setw(20) << wordAndCount.second << std::endl;
        }
    }
}
