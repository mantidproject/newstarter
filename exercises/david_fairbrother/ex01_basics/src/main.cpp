
#include "main.h"

#include <fstream>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <iterator>
#include <cctype>

using namespace std;

#define ERR_BAD_PROGRAM_ARG 1
#define ERR_OPENING_FILE 2

#define OUT_FILE_NAME "outfile.txt"
#define MIN_WORD_SIZE 4

int main(int argc, char ** argv)
{
	
	//Program name counts as first argument so 2 is required
	if (argc != 2) {
		cerr << "Incorrect argument, one file path should be entered.";
		return ERR_BAD_PROGRAM_ARG;
	} 

	ifstream fileHandle;
	//Pass the second argument as first is program name
	//Try to open file and store result in state or throw exception upwards
	try {
		openFileHandle(argv[1], fileHandle);
	}
	catch (const char* e) {
		cerr << e << endl << "Exiting" << endl;
		return ERR_OPENING_FILE;
	}

	vector<pair<string, int> > uniqueWordCount = countUniqueWords(fileHandle);


	ofstream outFile;
	//Should ask for destination or possibly check second arg for output filename
	outFile.open(OUT_FILE_NAME); 

	printUniqueWords(uniqueWordCount, outFile);


}


// Counts the number of unique words and stores it as a sorted vector
vector<pair<string, int> > countUniqueWords(ifstream &fileHandle) {

	//Count in unique words
	 map<string, int> uniqueWordsMap = readWordsFromFile(fileHandle, MIN_WORD_SIZE);

	 //Then move into a vector so it can be sorted by val instead of by key
	 vector<pair<string, int> > wordCounts;
	 move(uniqueWordsMap.begin(), uniqueWordsMap.end(), back_inserter(wordCounts));

	 sort(wordCounts.begin(), wordCounts.end(), sortPairsByVal);

	return wordCounts;

}

//	Opens a file handle at specified path throws exception if unsuccessful
void openFileHandle(const char* filePath, ifstream &fileHandle) {

	fileHandle.open(filePath, ifstream::in);

	if (!fileHandle) {
		//Failed to open - print error and reason
		cerr  << strerror(errno);
		throw "Could not open file";
	}
}

// Reads from file handle and splits words of a minimum size into a map which is returned
map<string, int> readWordsFromFile(ifstream &fileHandle, int minWordSize) {

	bool wordPresent = false;
	map<string, int> wordCount;

	int wordBufSize = 0;
	string wordBuffer;

	char c;

	/* Whilst a sentence at a time could be read we would still have to *
	 * parse each char at a time so parse as we read in					*/
	while (fileHandle.get(c)) {
		if (isalpha(c)) {
			//Push onto current word buffer
			wordBuffer += c;
			++wordBufSize;
			wordPresent = true;
		}
		else {
			//Check if a word exists in the current buffer and push that on
			if (wordPresent && wordBufSize >= minWordSize) {
				//Map the current word and increment its count
				++wordCount[wordBuffer];
			}
			//Always reset buffer after hitting whitespace
			wordPresent = false;
			wordBufSize = 0;
			wordBuffer.erase();
		} 

	} //End of while

	return wordCount;
}

// Sorts map pairs based on their value 
bool sortPairsByVal(const pair<const string, int> &i, const pair<const string, int> &j) {

	//This could be turned into a template for compile time polymorphism but this is overkill for this exercise
	return i.second > j.second;
}

// Prints the list of unique words to file, throws exception if cannot open output stream
void printUniqueWords(const vector<pair<string, int> > &toPrint, ostream &output) {

	output << "Word" << "\t\t" << "Usage" << endl;;
	//Type def to clean up for loop
	typedef vector<pair<string, int> > pairsVect;

	for (pairsVect::const_iterator it = toPrint.begin(); it != toPrint.end(); ++it) {
		output << it->first << "\t\t" << it->second << endl;
	}
}