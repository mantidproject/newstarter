#include <iostream>
#include <string>
#include <fstream>
#include "counter.h"

/**
 * WordCounter: produces a table of word frequencies from a text document
 *
 * Main routine for WordCounter
 * Get filename from arguments and create a Counter to count words
 */
int main(int argc, char ** argv)
{
	// parse command-line arguments
	if (argc == 3)
	{
		Counter counter;

		// Open input file
		std::cout << "Reading " << argv[1] << "..." << std::endl;
		std::ifstream file(argv[1]);

		// Count words
		if (!file.bad())
		{
			std::string str;
			while (file >> str) 
			{
				counter.add(str);
			}
		}

		// Open output file
		std::ofstream outfile(argv[2]);
		if (!outfile.bad())
			counter.generateReport(outfile);

	}
	else
	{
		std::cout << "Usage: WordCounter.exe <input-filename> <output-filename>" << std::endl;
	}

	return 0;
}