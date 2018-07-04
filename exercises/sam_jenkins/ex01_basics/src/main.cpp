/**
 * Skeleton main routine
 */
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <functional>
#include <unordered_map>
#include <regex>
#include <iomanip>
#include <sstream>
#include <vector>

using std::ifstream; using std::string; using std::cout; using std::endl; using std::istreambuf_iterator; 
using std::unordered_map; using std::vector;


bool space(const char& c)
{
	return (isspace(c)||c=='-');
}

bool not_space(const char& c)
{
	return !(isspace(c)||c=='-');
}

void add_string(string input, unordered_map<string, int>& outtable) {
	while (input.length() > 4 && (input.back() == ' ' || input.back() == '.' ||
		input.back() == ',' || input.back() == '?' || input.back() == '\'' ||
		input.back() == '\"' || input.back() == '!' || input.back() == ':' ||
		input.back() == ')' || input.back() == ';')) {
		
		input.pop_back();
	}
	if (input.front() == '\'' || input.front() == '\"' || input.front() == '(') {
		
		input.erase(0, 1);
		
	}
	if (input.length() > 4) {
		
		++outtable[input];
	}
}

unordered_map<string, int> countof(const string& input)
{	
	unordered_map<string, int>wordtable;


	
	std::istringstream iss(input);
	
	auto i = input.begin();
	while(i != input.end()) {
		
		i = find_if(i, input.end(), not_space);
	
		auto j = find_if(i, input.end(), space);
		
		if (i != input.end()) {
			
			add_string(string(i, j), wordtable);
			i = j;
		}
	}
	return wordtable;
}

vector<std::pair<string,int>> mapToVector(unordered_map<string, int>map)
{
	vector<std::pair<string, int>> sortingVector(map.begin(), map.end());
	std::sort(sortingVector.begin(), sortingVector.end(), [](auto &left, auto&right) {
		return left.second < right.second;});
	return sortingVector;
}


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
		for (vector<std::pair<string, int>>::const_iterator it = output.begin();
			it != output.end(); ++it) {
			cout<<std::setw(15) << it->first <<std::setw(6) << it->second << endl;
		}
	}
	
	return 0;
}