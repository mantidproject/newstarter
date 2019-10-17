#ifndef SPLIT_LINE_INTO_WORDS_H_
#define SPLIT_LINE_INTO_WORDS_H_

#include <vector>
#include <string>
#include <cctype>
#include <algorithm>

// Splits a string into its asscoiated words, separated by hyphens and spaces. 
std::vector<std::string> splitLineIntoWords(const std::string& line);

#endif // end #ifndef SPLIT_LINE_INTO_WORDS_H_