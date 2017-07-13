#include "WordManipulation.h"
#include <algorithm>

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
	word.erase(remove_if(word.begin(), word.end(), isPunctuation), word.end());
}

/** checks if a character is punctuation /
*
* @param c Character to be checked
* @return true if c is punctuation, otherwise false
*
*/
bool isPunctuation(const char& c)
{
	string punctuation = ".,?'\"!():;";
	return punctuation.find(c) != string::npos;
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