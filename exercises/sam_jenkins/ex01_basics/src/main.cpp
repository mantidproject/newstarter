#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include "MapFunctions.h"


using namespace std;


int main(int argc, char **argv) {
	//check for valid number of arguements
	if (argc !=2) {
		cout << "This Program requires a single input" << endl;
			return 1;
	}
	//open the input stream
	ifstream in(argv[1]);

	if (!in) {
		cout << "could not find file: " << argv[1] << endl;
		return 1;
	}else{
		
		//if the stream opened properly, read the entire file to a string, then make the string all lowercase.
		string read((istreambuf_iterator<char>(in)), (istreambuf_iterator<char>()));
		transform(read.begin(), read.end(), read.begin(), ::tolower);

		//create an unordered map to count words
		const auto count = countof(read);
		//convert it to a sorted vector of pairs
		using vecPair = vector<std::pair<string, int>>;
		const vecPair output = mapToVector(count);
		//output to the file Out.txt
		ofstream outputFile("Out.txt");
		outputFile << std::setw(15) << "word" << std::setw(9) << "usage" << endl << endl;

		for (vecPair::const_iterator it = output.begin();
			it != output.end(); ++it) {
			outputFile << std::setw(15) << it->first << std::setw(6) << it->second << endl;
		}

		outputFile.close();
		in.close();
	}
	
	return 0;
}