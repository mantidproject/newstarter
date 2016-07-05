#ifndef MAIN_H
#define MAIN_H

#include <iosfwd>
#include <map>
#include <vector>

/* Counts the number of unique words and stores it as a sorted vector	*
* Returns 0 if successful or 0 if unsuccessful							*/
std::vector<std::pair<std::string, int> > countUniqueWords(std::ifstream &fileHandle);


/*	Opens a file handle at specified path	*
 *	Throws exception if unsuccessful		*/
void openFileHandle(const char* filePath, std::ifstream &fileHandle);

/* Reads from file handle and splits words of a minimum size into a map */
std::map<std::string, int> readWordsFromFile(std::ifstream &fileHandle, int minWordSize);

/* Sorts map pairs based on their value */
bool sortPairsByVal(const std::pair<const std::string, int> &i, const std::pair<const std::string, int> &j); 

/* Prints the list of unique words to file, throws exception if cannot open output stream*/
void printUniqueWords(const std::vector<std::pair<std::string, int> > &toPrint, std::ostream &output);


#endif
