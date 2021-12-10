#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <map>
#include <vector>
#include <algorithm>
#include <assert.h>
#include <functional>

#include "Header.h"
#include "ci_less.cpp"

class fileReader {
public:
	fileReader(std::string& sFileName, std::string& sFilePath) { //take in user input regarding filepath
		assert(!sFileName.empty()); //ensure file name + path entered
		assert(!sFilePath.empty());

		loadFile(sFileName, sFilePath); //load file to stream
	}

	void getUniques(int& minChars, bool caseSens) { //get unique words longer than minchars
		std::string tempLine;
		std::string sWord;

		while (_file.good()) {
			std::getline(_file, tempLine);

			std::istringstream iss(tempLine);

			do { //go word by word
				iss >> sWord;

				evalWord(sWord, '-', minChars); //evaluate work, using - as seperating delim

				sWord = ""; //reset word string after eval
			} while (iss);
		}
	}

	void sortAndOutputMap(std::string& sFileName, std::string& sFilePath, bool& bAccending){ //take map, flip + transfer to multimap sorted decendingly
		std::string sFullReturnPath = sFilePath + "\\" + sFileName + ".txt";
		std::ofstream stream;

		assert(!sFileName.empty()); //check presence of user input (results destination + file name)
		assert(!sFilePath.empty());

		try { //try to open specified file, throw error if invalid
			stream.open(sFullReturnPath);
			if (!_file.is_open()) {
				throw std::ios::failure("Error opening file!");
			}
		}

		catch (const std::exception& e) {
			std::cout << sFullReturnPath << " Invalid Path - Return File Could Not be Created\n";
			abort();
		}

		std::multimap<int, std::string, std::greater<int>> orderedWords = flip_map(_uniqueWords); //flip each pair in map + transfer to multimap

		for (auto& kv : orderedWords) { //output multimap in opened file
			stream << kv.second << " - " << kv.first << '\n';
		}
		stream.close();
		std::cout << " Write to Results File " << sFullReturnPath << " Complete \n";
	}

private:
	std::ifstream _file;
	std::map<std::string, int, ci_less> _uniqueWords;

	void loadFile(std::string& sFileName, std::string& sFilePath) {
		std::string sFullPath = sFilePath + "\\" + sFileName + ".txt";

		try{ //try to open specified file, throw error if invalid
			_file.open(sFullPath, std::ios::in);
			if (!_file.is_open()) {
				throw std::ios::failure("Error opening file!");
			}
		}

		catch (const std::exception& e){
			std::cout << sFullPath << " File Load Failed\n";
			abort();
		}

		std::cout << sFullPath << " Loaded Successfully \n";
	}

	void evalWord(std::string& sWord, char splitDelim, int& minChars) { //evaluate if input word should be recorded
		if (sWord.length() >= minChars) { //if word fulfils min char criteria
			if (sWord.find(splitDelim) != std::string::npos) { //if split delim in word, split into vector by delim and loop through elements
				std::vector<std::string> splitVec;
				std::vector<std::string>::iterator it;

				splitVec = strToVec(sWord, splitDelim);

				for (it = splitVec.begin(); it != splitVec.end(); it ++) {
					checkLenAndRecord(*it, minChars); //after split, remove punct, re-check word length and record
				}
			}
			else {
				checkLenAndRecord(sWord, minChars); //remove punct, re-check word length, record
			}
		}
	}

	void checkLenAndRecord(std::string& sWord, int& minChars) {
		sWord.erase(remove_if(sWord.begin(), sWord.end(), ispunct), sWord.end()); //loop through string, erase punct

		if (sWord.length() >= minChars) { //reeval word length after removal of punct
			if (_uniqueWords.find(sWord) == _uniqueWords.end()) {
				// not found
				_uniqueWords.insert(make_pair(sWord, 1)); //if criteria met store in map
			}
			else {
				_uniqueWords[sWord] = _uniqueWords[sWord]++;
			}
		}
	}

	std::vector<std::string> strToVec(std::string& sWord, char& delim) { //take string, split by delin char, put resulting elements into vec
		std::vector<std::string> returnVec;
		std::string subWord;

		std::stringstream  data(sWord);

		while (std::getline(data, subWord, delim)) //get new lines by delim char
		{
			returnVec.push_back(subWord);
		}

		return returnVec;
	}
};

class cl_interface{ //command line interface
//NOTE: Commented out code is included to make case sensitivity + sort order variable (not fully implemented)

public:
	cl_interface() {
		std::string sFileName = "";
		std::string sFolderPath = "";
		std::string sResFileName = "";
		std::string sResFolderPath = "";
		std::string sCaseSensitive = "false";
		std::string sAccending = "true";
		bool bCaseSensitive;
		bool bAccending;
		int minLength = 0;

		std::cout << "Please Enter Read File Name (without Path): ";
		std::getline(std::cin, sFileName);
		std::cout << "Please Enter Read Folder Path: ";
		std::getline(std::cin, sFolderPath);

		fileReader test(sFileName, sFolderPath);

		std::cout << "Please Enter Minimum Word length to Parse (integer): ";
		std::cin >> minLength;
		if (std::cin.fail()) { //check for non integer entry
			std::cout << "Please Enter Valid Integer";
			abort();
		}

		std::cin.ignore(); //needed to allow following use getline

		//std::cout << "Case Sensitive Parse? (true/false=default): ";
		//getline(std::cin, sCaseSensitive);

		if (sCaseSensitive == "true" || sCaseSensitive == "True" || sCaseSensitive == "TRUE") {
			bCaseSensitive = true;
		}else if (sCaseSensitive == "false" || sCaseSensitive == "False" || sCaseSensitive == "FALSE") {
			bCaseSensitive = false;
		}else {
			std::cout << "Please Enter either 'true' or 'false'";
			abort();
		}

		test.getUniques(minLength, bCaseSensitive);

		std::cout << "Please Enter Desired Results File Name (without Path): ";
		std::getline(std::cin, sResFileName);
		std::cout << "Please Enter Desired Results Folder Path: ";
		std::getline(std::cin, sResFolderPath);

		//std::cout << "Sort in Accending Order? (true=default/false): ";
		//std::getline(std::cin, sAccending);

		if (sAccending == "true" || sAccending == "True" || sAccending == "TRUE") {
			bAccending = true;
		}
		else if (sAccending == "false" || sAccending == "False" || sAccending == "FALSE") {
			bAccending = false;
		}
		else {
			std::cout << "Please Enter either 'true' or 'false'";
			abort();
		}

		test.sortAndOutputMap(sResFileName, sResFolderPath, bAccending);
	}
};


int main() {
	cl_interface Test;

	return 0;
}


