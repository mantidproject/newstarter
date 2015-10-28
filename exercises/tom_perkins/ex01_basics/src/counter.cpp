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
 * Compares two (word, frequency) pairs to enable sorting.
 * Sorting is done in descending order of usage i.e. the pair with higher frequency comes first.
 */
bool compareRecords(const std::pair<std::string, int>& x, const std::pair<std::string, int>& y)
{
	return x.second > y.second;
}

/**
 * Writes a table of words and frequencies to supplied stream.
 * Words are sorted in descending order of usage.
 */
void Counter::generateReport(std::ostream& stream)
{
	// Write header
	stream << "Word" << "\t" << "Usage" << std::endl;

	// Copy map contents into a vector so they can be sorted
	std::vector<std::pair<std::string, int> > records;
	for (auto record : m_dictionary)
	{
		records.push_back(record);
	}
	// sort by pair value i.e. word frequency
	std::sort(records.begin(), records.end(), compareRecords);

	// Write output
	for (auto record : records)
	{
		stream << record.first << "\t" << record.second << std::endl;
	}
}


