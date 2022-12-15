#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <regex>
#include <unordered_map>
#include <cstring>
#include <iomanip>

std::string readFile(const std::string &filepath)
{
    std::ifstream inputStream(filepath);

    if (inputStream)
    {
        std::ostringstream ss;
        ss << inputStream.rdbuf();
        return ss.str();
    }
    else
    {
        throw std::invalid_argument("Invalid path. Please make sure the file path is correct and the file exists.");
    }
}

std::vector<std::string> tokenizeFile(const std::string &file)
{
    std::regex re("[-\\s]");
    std::sregex_token_iterator first{file.begin(), file.end(), re, -1}, last;
    std::vector<std::string> tokens{first, last};
    return tokens;
}

std::unordered_map<std::string, uint32_t> countWords(const std::vector<std::string> words)
{
    std::unordered_map<std::string, uint32_t> wordsCounts;
    for (auto word : words)
    {
        std::transform(
            word.begin(), word.end(), word.begin(),
            [](unsigned char c)
            { return std::tolower(c); });
        word.erase(std::remove_if(word.begin(), word.end(), ispunct), word.end());
        if (word.length() > 4)
        {
            wordsCounts[word]++;
        }
    }
    return wordsCounts;
}

void sortAndWriteWords(const std::unordered_map<std::string, uint32_t> &wordsCounts, const std::string &outputDir)
{
    std::vector<std::pair<std::string, int>> wordsCountsPairs;
    for (auto &pair : wordsCounts)
    {
        wordsCountsPairs.push_back(pair);
    }
    std::sort(
        wordsCountsPairs.begin(), wordsCountsPairs.end(),
        [](auto &left, auto &right)
        {
            return left.second > right.second;
        });

    std::ofstream outputFile(outputDir + "\\output.txt");

    outputFile << std::setw(20) << std::left << "Word" << std::setw(20) << std::left << "Usage"
               << "\n\n";

    for (auto &it : wordsCountsPairs)
    {
        outputFile << std::setw(20) << std::left << it.first << std::setw(20) << std::left << it.second << "\n";
    }

    outputFile.close();
    std::cout << "Found " << wordsCountsPairs.size() << " words and their counts have been successfully written in this path: " << outputDir + "\\output.txt"
              << "\n";
}

int main(int, char **)
{
    while (true)
    {
        std::cout << "Welcome to the Word Counter program!"
                  << "\n\n";
        std::cout << "This program will count the number of occurrences of unique words (longer than 4 characters and split hyphenated words, treating each part as different words)"
                  << "\n";
        std::cout << "The count will be case and punctuation insensitive"
                  << "\n\n";
        std::cout << "Please enter the path of the file:"
                  << "\n";
        std::string inputFilePath;
        getline(std::cin, inputFilePath);

        std::string file;
        try
        {
            file = readFile(inputFilePath);
            if (file.empty())
            {
                std::cout << "Note: "
                          << "This file is empty so the output will be an empty file."
                          << "\n";
            }
        }
        catch (std::invalid_argument e)
        {
            std::cerr << "Error:" << e.what() << "\n\n";
            continue;
        }

        std::vector<std::string> tokenizedFile = tokenizeFile(file);
        std::unordered_map<std::string, uint32_t> wordsCounts = countWords(tokenizedFile);

        std::string outputFileDir = inputFilePath.substr(0, inputFilePath.rfind('\\'));
        sortAndWriteWords(wordsCounts, outputFileDir);

        break;
    }

    return 0;
}