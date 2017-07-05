/*! Counts the frequency of words in a plain ascii file.
 * The words must be longer than four letters to be counted.
 * Hyphenated words count seperately.
 *
 * One argument: input file path
 *
 * Ranks words in descending frequency and saves to [input file path + "_Word_Rank"].
 *
 */

// Includes
#include "counter.h"

#include <cctype>
#include <fstream>
#include <iostream>
#include <map>
#include <stdlib.h>
#include <string>

int main(int argc, char* argv[])
{
	//Check if file name given
	if (argc < 2){
		std::cerr << "File name not given" << std::endl;
		return EXIT_FAILURE;
	}
	else {
		//Open file, and check that it exists
		std::ifstream inFile(argv[1]);

		if (!inFile){
			std::cerr << "The file \"" << argv[1] << "\" does not exist" << std::endl;
			return EXIT_FAILURE;
		}
		else{
			std::string line;
			//Store each word and an associated counter
			wordMap counters;

			//Count all the words in the file.
			while(std::getline(inFile, line))
				countWords(line, counters);

			//Create output file, check operation success
			std::string outFilePath = argv[1];
			outFilePath += "_Word_Rank";
			std::ofstream outFile(outFilePath);

			if(!outFile){
				std::cerr << "The file path\"" << outFilePath << "\" does not exist" << std::endl;
				return EXIT_FAILURE;
			}
			else
				rankWords(counters, outFile);

			return EXIT_SUCCESS;
		}
	}
}
