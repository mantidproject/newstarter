/**
 * Skeleton main routine
 */


#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include "../include/splitLineIntoWords.h"





namespace{
    const int MIN_WORD_LENGTH=5;
}

// Remove punctuation from the input word
int removePunctuation(std::string &iString)
{

    std::string::iterator itr = iString.begin() ;

    static const std::string punctuation(".!,\"?!");

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
bool compareWordCounts(std::pair<std::string,int> a,std::pair<std::string,int> b)
{
    return (a.second > b.second);
}



int main(int argc, char * argv[])
{


    // Initial variables
    std::ifstream file;
    bool fileopen = false;

    if ( argc < 2)
    {
        std::cout << "Error: No filename entered." << std::endl;
        return -1;
    }

    // Open file
    std::string input_filename(argv[1]);
    file.open(input_filename);

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
                    auto retPair = wordCounts.insert(std::pair<std::string,int>(word,1));

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

    // Extract each <word,count> pair into a vector container
    std::vector<std::pair<std::string,int>> sortedWordCount;
    
    for (auto word : wordCounts)
    {
        sortedWordCount.push_back(word);

    }

    // Sort words by occurance using compare function
    sort(sortedWordCount.begin(),sortedWordCount.end(),compareWordCounts);


    // Output words into a file
    std::string output_filename = "sorted_" + input_filename ;
    std::ofstream outputfile(output_filename, std::ofstream::out);
    
    if (outputfile.is_open())
    {
        outputfile << std::setw(20) << "Word" << std::setw(20) << "count" << std::endl;
        for (auto wordAndCount : sortedWordCount)
        {
            outputfile << std::setw(20) << wordAndCount.first << std::setw(20) << wordAndCount.second << std::endl;
        }
    }
}
