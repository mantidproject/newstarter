#include <iostream>

/**
 * Main routine for WordCounter
 * Get filename from arguments and create a WordCounter to count words
 */
int main(int argc, char ** argv)
{
	// parse command-line arguments
	if (argc == 2)
	{
		std::cout << "Reading " << argv[1] << "..." << std::endl;
	}
	else
	{
		std::cout << "Usage: WordCounter.exe <filename>" << std::endl;
	}

	return 0;
}