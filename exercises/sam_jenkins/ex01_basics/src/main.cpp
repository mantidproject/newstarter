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
		cout << "You must run this program with an arguement" << endl;
			return 1;
	}
	//open the input stream
	ifstream in(argv[1]);
	if (in) {
		//if the stream opened properly, read the entire file to a string, then make the string all lowercase.
		string read((istreambuf_iterator<char>(in)), (istreambuf_iterator<char>()));
		transform(read.begin(), read.end(), read.begin(), ::tolower);

		//cout << read << endl;
		unordered_map<string, int> count =countof(read);
		vector<std::pair<string, int>> output = mapToVector(count);
		ofstream outputfile("Out.txt");
		outputfile << std::setw(15) << "word" << std::setw(9) << "usage" << endl << endl;
		for (vector<std::pair<string, int>>::const_iterator it = output.begin();
			it != output.end(); ++it) {
			outputfile <<std::setw(15) << it->first <<std::setw(6) << it->second << endl;
		}
	}
	
	return 0;
}