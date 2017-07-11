#include "main.h"

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
	string word;
	
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
	size_t space;

	space = line.find(" ");
	while (space != string::npos)
	{
		word = line.substr(0, space);
		++space;
		line = line.substr(space);
		addWord(words, word);
		space = line.find(" ");
	}
	addWord(words, line);
}

/** Adds a word to a given map if applicable
*
* @param words The map of words to add to
* @param word The word to be added
*
*/
void addWord(map<string, int>& words, string& word)
{
	map<string, int>::const_iterator existing;
	word = removePunctuation(word);
	if (word.length() > 4)
	{
		word = toLower(word);

		existing = words.find(word);
		
		if (existing == words.end()) 
		{
			//if word isn't already in map, add it with quantity 1
			words.insert(std::pair<string, int>(word, 1));
		}
		else
		{
			//if word already exists in map, increment its quantity
			words[word]++;
		}
	}
}

/** Removes punctuation from the start or end of a string
*
* @param word The string to have punctuation removed
* @return The string without leading or trailing punctuation
*
*/
string removePunctuation(string& word)
{
	//check end of word
	while (word.length() > 1 && !isalpha(word[word.length() - 1]))
		word = word.substr(0, word.length() - 1);

	//check start of word
	while (word.length() > 1 && !isalpha(word[0]))
		word = word.substr(1);

	return word;
}

/** Converts a string to lowercase
*
* @param word The string to convert to lowercase
* @return The string in lowercase
*
*/
string toLower(string& word)
{
	int i = 0;
	while (i < word.length() && isupper(word[i]))
	//note loop terminates if it finds a lowercase character (assumes rest to be lowercase)
	{
		word[i] = tolower(word[i]);
		i++;
	}
	return word;
}

/** Converts a map of words into a vector of pairs and sorts (descending by value)
*
* @param words The map of words to be sorted
* @return A sorted vector of word-value pairs
*
*/
vector<pair<string, int>> sortWords(map<string, int>& words)
{
	vector<std::pair<string, int>> wordsVector;
	map<string, int>::iterator iter;

	for (iter = words.begin(); iter != words.end(); ++iter)
	{
		wordsVector.push_back(*iter);
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
void outputCount(vector<pair<string, int>>& words)
{
	ofstream output;
	auto iter = words.cbegin();
	string word;

	output.open("Output.txt");
	output << "Word" << setw(16) << "Usage" << "\n" << "\n";

	while(iter != words.cend())
	{
		word = (iter->first).c_str();
		output << word << setw(20 - word.length()) << iter->second << '\n';
		++iter;
	};
	return;
}
