#include <unordered_map>
#include <sstream>
#include <vector>
#include "stringManip.h"



using std::string; using std::unordered_map; using std::vector; using std::pair;

unordered_map<string, int> countof(const string& input)
{
	//create a unordered map and string input stream
	unordered_map<string, int>wordtable;
	//create an iterator to loop through the string
	auto i = input.begin();
	while (i != input.end()) {
		//find the first non space character
		i = find_if_not(i, input.end(), space);
		//find the next space from that point
		auto j = find_if(i, input.end(), space);
		//take the substring between i and j, strip it of punctuation and add it to the map
		if (i != input.end()) {
			string current(i, j);
			strip_string(current);
			if (current.length() > 4) {
				++wordtable[current];
			}
			//move i to js location
			i = j;
		}
	}
	return wordtable;
}

bool compare(const pair<string, int>& left, const pair<string, int>& right)
{
	return left.second > right.second;
}

vector<std::pair<string, int>> mapToVector(unordered_map<string, int>map)
{
	//iterate across the map, copying it into a vector of pairs
	vector<std::pair<string, int>> sortingVector(map.begin(), map.end());
	//sort the vector via the second value descending
	std::sort(sortingVector.begin(), sortingVector.end(), compare);
	return sortingVector;
}

