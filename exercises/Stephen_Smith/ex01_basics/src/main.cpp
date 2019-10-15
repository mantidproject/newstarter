/**
 * Skeleton main routine
 */


#include <iostream>
#include <fstream>
#include <map>
#include <iomanip>
#include "../include/split.h"





namespace{
    const int MIN_WORD_LENGTH=5;
}

// Remove punctuation from an input string
int removePunctuation(std::string &iString)
{

    std::string::iterator itr = iString.begin() ;

    while (itr != iString.end())
    {

        char c = *itr;
        if ( (c == '.') || (c == '!') || (c == ',') ||(c == '\'') || (c == '\"') || (c == '?'))
        {
            itr = iString.erase(itr);
        }else{
            ++itr;
        }

    }

    return 0;

}
// Function to compare number of times a word has been seen
bool compareWordCounts(std::pair<std::string,int> a,std::pair<std::string,int> b)
{
    return (a.second > b.second);
}



int main(int argc, char ** argv)
{


    // Initial variables
    std::string input_filename;
    std::ifstream file;
    bool fileopen = false;

    // Request filename from user
    while ( fileopen != true){

        std::cout << "Input filename: " ;
        std::cin >> input_filename;

        file.open(input_filename);

        if (file.is_open())
        {
            fileopen = true;
        }else{
            std::cout << "ERROR: could not find file, enter new filename" << std::endl;
        }

    }

    // Map to store word, and asscoiated word count
    std::map<std::string,int> wordCounts;

    // Loop over each line of the file
    std::string line;

    while(getline(file,line))
    {

        std::vector<std::string> lineWords = split(line); 


        if (!lineWords.empty())
        {
            for (auto word : lineWords)
            {
                // make each word lower case
                std::transform(word.begin(),word.end(),word.begin(),::tolower);

                // remove punctuation
                removePunctuation(word);
                // count number of letters in word
                int word_length = word.length();
                
                // add word of length (>= MIN_WORD_LENGTH) to map container ;
                if ( word_length >= MIN_WORD_LENGTH)
                {
                    
                    auto retPair = wordCounts.insert(std::pair<std::string,int>(word,1));

                    if (retPair.second == false)
                    {
                        // element already existed, increment count
                        ++retPair.first->second;
                    }


                }

            }
        }
    }



    // close the file
    file.close();

    // Sort the words - put words into a vector container
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
    
    outputfile << std::setw(20) << "Word" << std::setw(20) << "count" << std::endl;
    for (auto wordAndCount : sortedWordCount)
    {
        outputfile << std::setw(20) << wordAndCount.first << std::setw(20) << wordAndCount.second << std::endl;
    }
    
}
