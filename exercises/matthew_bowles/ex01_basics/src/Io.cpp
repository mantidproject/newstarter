#include "Io.h"
#include "WordManipulation.h"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iomanip>


using namespace std;

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ofstream output;
		output.open("Output.txt");
		output << "Missing input file argument" << '\n';
		return 1;
	}
	map<string, int> words = loadFile(argv[1]);
	vector<pair<string, int>> sortedWords = sortWords(words);
	outputCount(sortedWords);
	return 0;
}


/** Loads word input from a file into a map 
*
* @param path The path to the input file
* @return A map of words and their number of uses
*
*/
map<string, int> loadFile(const string& path)
{
	map<string, int> words;
	ifstream fileIn;
	string line;
	
	fileIn.open(path);
	if (fileIn.is_open())
	{
		while (getline(fileIn, line))
		{
			splitLine(line, words);
		}
	}
	else cout << "unable to open file";
	return words;
}

/** Splits an input line into seperate words
*
* @param line The line to split
* @param words The map of words to hold the resulting words
*
*/
void splitLine(string& line, map<string, int>& words)
{
	string word;
	size_t delimiter;

	delimiter = min(line.find(" "), line.find("-"));
	while (delimiter != string::npos)
	{
		word = line.substr(0, delimiter);
		++delimiter;
		line = line.substr(delimiter);
		addWord(words, word);
		delimiter = min(line.find(" "), line.find("-"));
	}
	addWord(words, line);
}

/** Converts a map of words into a vector of pairs and sorts (descending by value)
*
* @param words The map of words to be sorted
* @return A sorted vector of word-value pairs
*
*/
vector<pair<string, int>> sortWords(const map<string, int>& words)
{
	vector<std::pair<string, int>> wordsVector;
	map<string, int>::iterator iter;

	for (const auto& word : words)
	{
		wordsVector.push_back(word);
	}
	sort(wordsVector.begin(), wordsVector.end(), compare);
	return wordsVector;

}

/** Compares two int values
*
* @param x First int to be compared
* @param y Second int to be compared
* @return Result of comparison
*
*/
bool compare(const pair<string, int>& x, const pair<string, int>& y)
{
	return x.second > y.second;
}

/** Outputs vector of word-value pairs to a file
*
* @param words The vector of word-value pairs to output
*
*/
void outputCount(const vector<pair<string, int>>& words)
{
	ofstream output;
	string word;

	output.open("Output.txt");
	output << "Word" << setw(16) << "Usage" << "\n" << "\n";

	for(auto& w : words)
	{
		word = w.first;
		output << word << setw(20 - word.length()) << w.second << '\n';
	};
	return;
}
