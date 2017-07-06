#ifndef COUNTER_H_
#define COUNTER_H_

//Includes
#include <iosfwd>
#include <map>
#include <string>

const std::string::size_type  MIN_LENGTH = 5;
const std::string PUNC = ".,?'\"!():;";
const std::string HYPHEN = "-";
const int OUT_WIDTH = 20;

typedef std::map<std::string, int> wordMap;
typedef std::multimap<int, std::string> wordRank;
typedef std::string::size_type string_size;

//Stores individual words and increments an associated counter
void countWords(std::string& line, wordMap& counters);

//Ranks words by frequency, as stores in ascii file.
void rankWords(wordMap& counters, std::ofstream& outFile);

//Turns wordMap into wordRank [multimap]
wordRank flipMap(wordMap& counters);

//Returns true if character is whitespace or punctuations (except hyphens)
bool isPunc(char c);

//Returns true if character is hyphen
bool isHyphen(char c);

#endif /* COUNTER_H_ */
