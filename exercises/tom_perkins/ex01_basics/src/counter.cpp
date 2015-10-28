#include "counter.h"

/**
 * Adds a word to the counter.
 * Increments count for that record if it has been seen previously,
 * otherwise adds a new record.
 */
void Counter::add(const std::string& word)
{
	++m_dictionary[word];
	// TODO: points in part 3 of exercise (word length, hyphens, case/punctuation)
}

/**
 * Writes a table of words and frequencies to supplied stream
 */
void Counter::generateReport(std::ostream& stream)
{
	for (auto record : m_dictionary)
	{
		stream << record.first << "\t" << record.second << std::endl;
	}
}
