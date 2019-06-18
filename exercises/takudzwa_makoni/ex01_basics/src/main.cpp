#include <iostream>
#include <fstream>
#include <iomanip>		
#include <string>		//std::string
#include <algorithm>	//std::transform
#include <cctype>		//std::tolower
#include <vector>


std::vector<std::string> searchList = { "which","holmes","there","could","photograph" }; // list of words to be searched.


struct ComparableToSpecial {

	ComparableToSpecial(char inChar) : inputChar(inChar) {}

	const char inputChar;
	bool operator()(char c) const { return c == inputChar;  }

};


// return true if special character exists in c.
bool isSpecialCharacter(char c)
{
	std::string specialChars = "()!?,.\":\\";
	if (std::any_of(specialChars.begin(), specialChars.end(), ComparableToSpecial(c))) { return true; }
	
}


struct ComparableTo {

	std::string character;
	ComparableTo(std::string ch) : character(ch) {};
	bool operator()(std::string ch) const { return ch == character; }
};

//count number of occurences in file and cout result
void printCount(const std::string& searchWord, std::ifstream& fileObj) {

	//std::string temp = searchWord; no longer required?


	int count = 0;
	std::string word; //word from file
	while (fileObj >> word) {
	
		std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) -> unsigned char { return std::tolower(c); }); 
		std::remove_if(word.begin(), word.end(), &isSpecialCharacter); 

	
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

