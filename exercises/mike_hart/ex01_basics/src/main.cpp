#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

/**
 * Main routine
 */
int main(int argc, char ** argv)
{
	// Ensure correct usage
	if (argc != 2)
	{
		std::cout << "Usage: WordCounter <filename>" << std::endl;
		system("pause");
		exit(1);
	}

	// Convenience typedefs
	typedef std::map<std::string, int> WordCountMap;
	typedef std::pair<std::string, int> PairType;
	typedef std::vector<PairType> SortableWordList;

	// Open input file
	std::ifstream infile(argv[1]);
	if (!infile.is_open())
	{
		std::cerr << "Could not open file: " << argv[1] << std::endl;
		system("pause");
		exit(1);
	}

	// Map of words -> usage count
	WordCountMap wordcount;

	// Read file line by line and count words
	for (std::string line; std::getline(infile, line); )
	{
		// Convert each line to lowercase
		std::transform(line.begin(), line.end(), line.begin(), ::tolower);

		// Process for tokens until line is empty
		while (!line.empty())
		{
			// Get next token
			auto pos = line.find_first_of("- \t.,?'\"!():");
			auto token = line.substr(0, pos);

			// Add counter for token if it's long enough
			if (token.length() > 4)
				wordcount[token]++;

			// Ensure remainder of line is erased if no delimiter found
			if (pos == std::string::npos) 
				pos = line.length();
			
			// Remove token and delimiter from front of line
			line.erase(0, pos + 1);
		}
	}

	// Construct vector of pairs from map that will be sorted by actual word count
	SortableWordList sortedcount;
	std::copy(wordcount.begin(), wordcount.end(), std::back_inserter(sortedcount));
	
	// Sort by word count, descending
	std::sort(sortedcount.begin(), sortedcount.end(), 
		[](const PairType& left, const PairType& right) {
			return left.second > right.second;
		}
	);

	// Write results to file
	std::ofstream outfile("Results.txt");
	outfile << std::setw(20) << std::left << "Word";
	outfile << "Usage Count" << std::endl << std::endl;

	for (const auto& pair : sortedcount)
	{
		outfile << std::setw(20) << std::left << pair.first;
		outfile << pair.second << std::endl;
	}

	system("pause");
}