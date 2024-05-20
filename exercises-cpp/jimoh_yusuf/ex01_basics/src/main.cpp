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

    if (!openFile.is_open()) {
        std::cerr << "Error: Unable to open the input file." << std::endl;
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

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <filename>" << std::endl;
        return 1;
    }

    const std::string inputFilePath = argv[1];

    std::ifstream openFile(inputFilePath);

    // check the file for errors
    if(!openFile.good()) {
        std::cout << "Error: Unable to open the path of the input file." << inputFilePath << std::endl;
        return 1;
    }
    std::map<std::string, int> wordCount = countWordOccurrences(inputFilePath);

}

