#include <iostream>
#include <string>
#include <fstream>
#include "counter.h"

/**
 * Main routine for WordCounter
 * Get filename from arguments and create a Counter to count words
 */
int main(int argc, char ** argv)
{
	// parse command-line arguments
	if (argc == 2)
	{
		std::cout << "Reading " << argv[1] << "..." << std::endl;

		// Open file
		std::ifstream file(argv[1]);
		if (!file.bad())
		{
			Counter counter;
			std::string str;
			while (file >> str) 
			{
				counter.add(str);
			}
			counter.generateReport(std::cout);
		}
	}
	else
	{
		std::cout << "Usage: WordCounter.exe <filename>" << std::endl;
	}

	return 0;
}