#include "WordManipulation.h"

/** Adds a word to a given map if applicable
*
* @param words The map of words to add to
* @param word The word to be added
*
*/
void addWord(map<string, int>& words, string& word)
{
	removePunctuation(word);
	if (word.length() > 4)
	{
		toLower(word);
		if (words.count(word) == 0)
		{
			//if word isn't already in map, add it with quantity 1
			words.insert(make_pair(word, 1));
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
*
*/
void removePunctuation(string& word)
{
	string punctuation = ".,?'\"!():";
	auto iter = word.begin();
	while (iter != word.end())
	{
		if (punctuation.find(*iter) != string::npos)
			iter = word.erase(iter);
		else
			++iter;
	}

}

/** Converts a string to lowercase
*
* @param word The string to convert to lowercase
*
*/
void toLower(string& word)
{
	std::transform(word.begin(), word.end(), word.begin(), ::tolower);
}