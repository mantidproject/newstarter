#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <cctype>
#include <algorithm>
#include <vector>
#include <regex>

struct CountCompare
{
	bool operator() (const std::pair<std::string, size_t>&p1, const std::pair<std::string, size_t>&p2) const
	{
		return p2.second < p1.second || !(p1.second < p2.second) && p1.first < p2.first;
	}
} cmp;

bool ContainsDashes(const std::string &compositeWord)
{
	return compositeWord.find('-') != std::string::npos;
}
std::vector<std::string> SplitWords(const std::string &compositeWord)
{
	// Containers for splitting up words
	std::vector<std::string> words;
	std::string segment;

	// Convert the composite word to a stream
	std::stringstream wordStream(compositeWord);

	// Split the elements of the stream using the '-' character and place these in the vector
	while (std::getline(wordStream, segment, '-'))
	{
		// Ignore empty words
		if (segment.length() == 0)
			continue;

		// Add the word to the vector
		words.push_back(segment);
	}

	return words;
}
void SaveWordCountToFile(const std::map<std::string, int> &wordMap, const std::string &outputFilename)
{
	// Attempt to open a file
	std::ofstream outFile;
	outFile.open(outputFilename);

	// Check that the file was opened successfully
	if (!outFile)
	{
		std::cout << "Error: Unable to open the file " << outputFilename << " for writing." << std::endl;
		exit(1);
	}

	// Declare a set for storing words by word count
	std::vector <std::pair<std::string, size_t>> wordSet(wordMap.begin(), wordMap.end());

	std::sort(wordSet.begin(), wordSet.end(), cmp);

	// Write the first few lines to the output file
	outFile << "Word" << "\t" << "Usage" << std::endl << std::endl;

	// Write the words and their count to the file using the sorted set
	for (const auto &p : wordSet)
	{
		outFile << p.first << "\t" << p.second << std::endl;
	}

	outFile.close();

}
std::map<std::string, int> CountWords(std::string inputFilename)
{
	// Declare a string for the words in the text 
	std::string words;

	// Attempt to open the text file
	std::ifstream inFile;
	inFile.open(inputFilename);

	// Check that the file was opened successfully
	if (!inFile)
	{
		std::cout << "Error: Unable to open the file " << inputFilename << " for reading." << std::endl;
		exit(1);
	}

	// Declare a map for storing the word counts
	std::map<std::string, int> wordMap;

	// Declare regex for removing punctuation characters
	std::regex unwantedChars("[.,?'\"!():;]");
	char emptyChar = 0;

	// Traverse through the file
	while (!inFile.eof())
	{
		// Store the word in a string
		inFile >> words;

		// Convert the word(s) to lower case
		std::transform(words.begin(), words.end(), words.begin(), static_cast<int(*)(int)>(std::tolower));

		// Create a vector for storing the words after they've been split
		std::vector<std::string> splitWords;

		if (ContainsDashes(words))
		{
			// Remove dashes from the words if any are present
			splitWords = SplitWords(words);
		}
		else
		{
			// Place the single word in the vector when no dashes are present
			splitWords.push_back(words);
		}

		for (auto word = begin(splitWords); word != end(splitWords); ++word) 
		{
			// Make the word suitable for the word map by removing punctuation characters
			*word = std::regex_replace(*word,unwantedChars,&emptyChar);

			// Check that the word has at least five characters
			if (word->length() <= 4)
				continue;

			// Place the word in the word map
			wordMap[*word]++;
		}
	}

	inFile.close();

	return wordMap;
}
int main(int argc, char *argv[])
{
	// Declare a string for input/output filenames
	std::string inputFilename;
	std::string outputFilename;

	// Check that the correct number of arguments were given
	if (argc == 3)
	{
		inputFilename = argv[1];
		outputFilename = argv[2];
	}
	else
	{
		std::cout << "Error: Incorrect number of arguments given. Expected 3." << std::endl;
		exit(1);
	}

	// Pass the filename argument to the word count function to obtain a word map
	std::map<std::string, int> wordMap = CountWords(inputFilename);

	// Pass the populated word map and the output filename to a function for writing these results to a file
	SaveWordCountToFile(wordMap,outputFilename);
}
