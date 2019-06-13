
#include "pch.h"
#include <iostream>
#include <fstream>
#include <list>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cctype>
#include <iomanip>


using namespace std;
list<string> searchList = {"which","holmes","there","could","photograph"}; // list of words to be searched.


// return true if special character exists in c.
bool isSpecialCharacter(char c)
{
	switch (c)
	{
	case '(':
	case ')':
	case '.':
	case ',':
	case '"': // still need backslash?
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
void printCount(const string& searchWord, ifstream& fileObj) {
	
	//std::string temp = searchWord; no longer required?

	
	int count = 0;
	string word; //word from file
	while (fileObj >> word) {
		std::transform(word.begin(), word.end(), word.begin(), std::tolower); //convert all characters of word to lower
		word.erase(std::remove_if(word.begin(), word.end(), &isSpecialCharacter), word.end()); //remove special characters from word.
		
		if (word == searchWord) {
			++count;
		}
	}

	// table formatting
	const int formatWidth = 13;
	const char formatSeparator = ' ';

	//cout number of matches
	cout << left << setw(formatWidth) << setfill(formatSeparator) << searchWord;
	cout << left << setw(formatWidth) << setfill(formatSeparator) << count;
	cout << endl;

}


int main()
{
	ifstream testFile;
	testFile.open("Holmes.txt");

	if (!testFile.is_open()) {

		cout << "no such file." << endl;
	}

	else

	{
		cout << "file loaded successfully." << endl << endl;
		cout << "matches found:" << endl;
		
		// loop through searchlist
		for (list<string>::iterator iter = searchList.begin(); iter != searchList.end(); ++iter ) { 

			printCount(*iter, testFile); //cout search word and number of occurences.
			
			// return to beginning of file each iteration, otherwise other elements in searchList count 0.
			testFile.clear();
			testFile.seekg(0, ios::beg); 
		}

		cin.get();
		return 0;
	}

	testFile.close();

}

