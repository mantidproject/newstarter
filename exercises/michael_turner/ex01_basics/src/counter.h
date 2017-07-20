#ifndef COUNTER_H_
#define COUNTER_H_

//Includes
#include <iosfwd>
#include <map>
#include <string>

typedef std::map<std::string, int> WordMap;
typedef std::multimap<int, std::string> WordRank;

//Stores individual words and increments an associated counter
void countWords(std::string& line, WordMap& counters);

//Ranks words by frequency, as stores in ascii file.
void rankWords(WordMap& counters, std::ofstream& outFile);

#endif /* COUNTER_H_ */
