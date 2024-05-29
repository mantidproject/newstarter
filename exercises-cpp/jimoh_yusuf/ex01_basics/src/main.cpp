/**
 * Skeleton main routine
 */

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <regex>

// Function to remove punctuation and convert to lowercase
std::string cleanWord(const std::string& word) {
    std::regex punctuation("[.,?\"'!():]");
    std::string cleanedWord = std::regex_replace(word, punctuation, "");
    std::transform(cleanedWord.begin(), cleanedWord.end(), cleanedWord.begin(), ::tolower);
    return cleanedWord;
}

// Function to read words from file and count occurrences
std::map<std::string, int> countWordOccurrences(const std::string& inputFilePath) {
    std::ifstream openFile(inputFilePath);
    //declare a string to hold each word that
    // will be read from the file
    std::string word;
    //declare a map to store word and its count
    // create a map with integer keys and string values
    std::map<std::string, int> wordCount;

    // check the file for errors
    if(!openFile.good()) {
        std::cout << "Error: Unable to open the path of the input file." << inputFilePath << std::endl;
        return wordCount; // Return empty map if file cannot be opened
    }

    std::regex hyphen("-");
    while (openFile >> word) {
        word = cleanWord(word); // Clean word from punctuation and convert to lowercase

        std::sregex_token_iterator iter(word.begin(), word.end(), hyphen, -1);
        std::sregex_token_iterator end;
        while (iter != end) {
            std::string part = *iter;
            if (part.length() >= 4) {
                wordCount[part]++;
            }
            ++iter;
        }
    }

    openFile.close();
    return wordCount;
}

// Function to write word-count pairs to a results file
bool writeResultsToFile(const std::vector<std::pair<std::string, int> >& wordCount, const std::string& outputFilePath) {
    std::ofstream outputFile(outputFilePath);
    if (!outputFile.is_open()) {
        std::cerr << "Error: Failed to create the results file" << std::endl;
        return false;
    }

    outputFile << "Word\tUsage" << std::endl;
    outputFile << "----------------" << std::endl;

    for (const std::pair<std::string, int>& pair : wordCount) {
        std::cout << pair.first << "\t" << pair.second << std::endl;
        outputFile << pair.first << "\t" << pair.second << std::endl;
    }

    outputFile.close();
    return true;
}

// Comparison function for sorting
bool comparePairs(const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
    return a.second > b.second; // Sort by count in descending order
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::string inputFilePath = argv[1];

    std::map<std::string, int> wordCount = countWordOccurrences(inputFilePath);

    if (wordCount.empty()) {
        std::cerr << "Error: No valid words found in the file" << std::endl;
        return 1;
    }

    // Sort word-count pairs in descending order of usage
    std::vector<std::pair<std::string, int> > sortedWordCount(wordCount.begin(), wordCount.end());
    std::sort(sortedWordCount.begin(), sortedWordCount.end(), comparePairs);

    const std::string outputFilePath = "results.txt";
    if (!writeResultsToFile(sortedWordCount, outputFilePath)) {
        return 1; // Return error code if writing to file fails
    }

    std::cout << "Results written to " << outputFilePath << std::endl;
    return 0;
}

