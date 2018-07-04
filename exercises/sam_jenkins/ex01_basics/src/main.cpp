#include <iostream>
#include <fstream>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include "mapFunctions.h"


using std::ifstream; using std::string; using std::cout; using std::endl; using std::istreambuf_iterator; 
using std::unordered_map; using std::vector; using std::ofstream;


int main(int argc, char **argv) {
	//check for valid number of arguements
	if (argc !=2) {
		cout << "This Program requires a single input" << endl;
			return 1;
	}
	//open the input stream
	ifstream in(argv[1]);
	if (in) {
		//if the stream opened properly, read the entire file to a string, then make the string all lowercase.
		string read((istreambuf_iterator<char>(in)), (istreambuf_iterator<char>()));
		transform(read.begin(), read.end(), read.begin(), ::tolower);

		//create an unordered map to count words
		unordered_map<string, int> count =countof(read);
		//convert it to a sorted vector of pairs
		vector<std::pair<string, int>> output = mapToVector(count);
		//output to the file Out.txt
		ofstream outputfile("Out.txt");
		outputfile << std::setw(15) << "word" << std::setw(9) << "usage" << endl << endl;
		for (vector<std::pair<string, int>>::const_iterator it = output.begin();
			it != output.end(); ++it) {
			outputfile <<std::setw(15) << it->first <<std::setw(6) << it->second << endl;
		}
	}
	else {
		cout << "could not find file: " << argv[1] << endl;
	}
	
	return 0;
}