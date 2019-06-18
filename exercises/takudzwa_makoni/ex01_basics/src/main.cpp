#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <vector>


std::vector<std::string> searchList = { "which","holmes","there","could","photograph" }; // list of words to be searched.


// return true if special character exists in c.
bool isSpecialCharacter(char c)
{
	switch (c)
	{
	case '(':
	case ')':
	case '.':
	case ',':
	case '"':
	case '?':
	case '!':
	case '\'':
	case ':':
		return true;
	default:
		return false;
	}
}


//count number of occurences in file and cout result
void printCount(const std::string& searchWord, std::ifstream& fileObj) {

	//std::string temp = searchWord; no longer required?


	int count = 0;
	std::string word; //word from file
	while (fileObj >> word) {
		std::transform(word.begin(), word.end(), word.begin(), std::tolower); //convert all characters of word to lower
		std::remove_if(word.begin(), word.end(), &isSpecialCharacter); //remove special characters TODO possible implementation of std::any_of
		if (word == searchWord) {
			++count;
		}
	}

	// table formatting
	const int formatWidth = 13;
	const char formatSeparator = ' ';

	//cout number of matches
	std::cout << std::left << std::setw(formatWidth) << std::setfill(formatSeparator) << searchWord;
	std::cout << std::left << std::setw(formatWidth) << std::setfill(formatSeparator) << count;
	std::cout << "\n";

}


int main()
{
	std::ifstream testFile;
	testFile.open("Holmes.txt");

	if (!testFile.is_open()) {

		return 1;
	}

	else

	{
		std::cout << "file loaded successfully." << "\n\n";
		std::cout << "matches found:\n";

		// loop through searchlist

		for (const auto & word : searchList) {
			printCount(word, testFile); //cout search word and number of occurences.

			// return to beginning of file each iteration, otherwise other elements in searchList count 0.
			testFile.clear();
			testFile.seekg(0, std::ios::beg);
		}

		std::cin.get();

	}

	testFile.close();
	return 0;
}

