#include "counter.h"

//----------------------------------------------------------------------
// Free functions
//----------------------------------------------------------------------

namespace
{
	/**
	 * Compares two (word, frequency) pairs to enable sorting.
	 * Sorting is done in descending order of usage i.e. the pair with higher frequency comes first.
	 */
	bool compareRecords(const std::pair<std::string, int>& x, const std::pair<std::string, int>& y)
	{
		return x.second > y.second;
	}

	/**
	 * Checks if the supplied character is valid (not punctuation).
	 * Returns: true if ok, else false.
	 */
	bool isValidChar(char c)
	{
		static const std::string punctuation = ".,?'\"!():";

		return (find(punctuation.begin(), punctuation.end(), c) == punctuation.end());
	}

	/**
	 * Strips punctuation from the supplied word, and converts to lower case.
	 * Returns: cleaned-up word, or empty string if word was not valid
	 * (currently 'valid' means 'more than 4 characters')
	 */
	std::string validateWord(const std::string& word)
	{
		std::string validWord;
	
		for (auto i = word.begin(); i != word.end(); i++)
		{
			char c = *i;
			if (isValidChar(c))
			{
				c = tolower(c);
				validWord += c;
			}
		}

		// Empty the string if the word is too short
		if (validWord.size() <= 4)
			validWord.clear();

		return validWord;
	}
}

//----------------------------------------------------------------------
// Member functions
//----------------------------------------------------------------------

/**
 * Writes a table of words and frequencies to supplied stream.
 * Words are sorted in descending order of usage.
 */
void Counter::generateReport(std::ostream& stream) const 
{
	// Write header
	stream << "Word" << "\t" << "Usage" << std::endl;

	// Copy map contents into a vector so they can be sorted
	std::vector<std::pair<std::string, int> > records;
	for (auto iter = m_dictionary.begin(); iter != m_dictionary.end(); iter++)
	{
		records.push_back(*iter);
	}
	// sort by pair value i.e. word frequency
	std::sort(records.begin(), records.end(), compareRecords);

	// Write output
	for (auto iter = records.begin(); iter != records.end(); iter++)
	{
		stream << iter->first << "\t" << iter->second << std::endl;
	}
}

/**
 * Adds a word to the counter, after validating it.
 * Increments count for that record if it has been seen previously,
 * otherwise adds a new record.
 */
void Counter::add(const std::string& word)
{
	std::string validWord = validateWord(word);
	if (!validWord.empty())
		++m_dictionary[validWord];
}



