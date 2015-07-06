/* 
* File:   main.cpp
* Author: Elliot Oram
*/

/*Includes*/
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <iomanip>

/*Comaprison of frequency (descending)
 *Parameters: Two pairs of type <string, int> that are to be compared
 *Returns comparison int for two elements
 */
bool pairCompare(std::pair<std::string, int> firstElem, std::pair<std::string, int> secondElem) {
	return firstElem.second > secondElem.second;
}

/*Formats words before comparison to the list
 *Parameters: A string that represents the word to be formatted
 */
std::string formatWord(std::string word){
	/*change word to lower case*/
	for(int i = 0; i < word.size(); i++){
		word[i] = tolower(word[i]);
	}

	/*remove punctuation from word*/
	word.erase (std::remove_if(word.begin (), word.end (), ispunct), word.end ());

	return word;
}


/*Prints the vector elements to an output file
 *Parameters: vector of words and frequencys, name of the output file
 */
void printWords(std::vector< std::pair<std::string,int> > wordFrequency, std::string outFileName){
	//Find the length of the longest word
	int maxSize = wordFrequency[0].first.size();
	for(int i = 1; i < wordFrequency.size(); i++){
		int currentSize = wordFrequency[i].first.size();
		if(currentSize > maxSize){
			maxSize = currentSize;
		}
	}

	//Print out the words and frequencies to file
	std::ofstream outfile(outFileName.c_str());
	if (outfile.is_open())
	{
		outfile << std::setw(maxSize) << std::left << "Words" << std::setw(4) << "Frequency" << std::endl;
		for(int i = 0; i < wordFrequency.size(); i++){
			outfile << std::setw(maxSize) << std::left << wordFrequency[i].first << std::setw(4) << wordFrequency[i].second << std::endl;
		}
		outfile.close();
	}else{
		std::cout << "Unable to open file";
	}

}


int main(int, char *argv[]){

	/*File handling*/
	std::string fileName = argv[1];
	std::fstream file;
	file.open(fileName.c_str());

	/*Check file from command line arguement is valid*/ 
	while(file.is_open() == false){
		std::cout << "That file could not be opened, please enter a different name:";
		std::cin >> fileName;
		file.open(fileName.c_str());
	}

	/*Variable set up*/
	std::vector< std::pair<std::string, int> > wordFrequency;
	std::string word;

	/*Add first word and matching frequency initially*/
	std::cout << "Reading file..." << std::endl; 
	file >> word;
	word = formatWord(word);
	if(word.size() >= 4){
		std::pair<std::string,int> nextWord(word, 1);
		wordFrequency.push_back(nextWord);
	}

	/*loop until end of file*/
	while(!file.eof()){
		file >> word;
		word = formatWord(word);
		if(word.size() >= 4){
			int const VEC_SIZE = wordFrequency.size();	//size of the vector before adding
			int checks = 0;	//counter to ensure all words are checked for matches before adding
			if(VEC_SIZE == 0){
				std::pair<std::string,int> nextWord(word, 1);
				wordFrequency.push_back(nextWord);
			}
			
			for(int i = 0; i < VEC_SIZE; ++i){
				if(wordFrequency[i].first.compare(word) == 0){
					//increase frequency if word is already in the vector
					wordFrequency[i].second += 1;
				}else{
					checks++;
				}
			}
			if(checks == VEC_SIZE){
				//add the new word if it is not in the vector
				std::pair<std::string,int> nextWord(word, 1);
				wordFrequency.push_back(nextWord);
			}

		}
	}
	file.close();
	std::cout << "File closed" << std::endl;
	std::sort(wordFrequency.begin(), wordFrequency.end(), pairCompare);		//sort by frequency descending
	printWords(wordFrequency, argv[2]);
}