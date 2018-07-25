#include <unordered_map>
#include <sstream>
#include <vector>
#include "StringManip.h"

using namespace std;
const int MINIMUM_WORD_LENGTH = 4;
unordered_map<string, int> countof(const string& input)
{
	unordered_map<string, int>wordtable;
	auto stringIter = input.begin();

	while (stringIter != input.end()) {
		stringIter = find_if_not(stringIter, input.end(), space);
		auto spaceStringIter = find_if(stringIter, input.end(), space);

		if (stringIter != input.end()) {
			string current(stringIter, spaceStringIter);
			stripString(current);

			if (current.length() > MINIMUM_WORD_LENGTH) {
				++wordtable[current];
			}
			stringIter = spaceStringIter;
		}
	}
	return wordtable;
}


vector<std::pair<string, int>> mapToVector(unordered_map<string, int>map)
{
	vector<std::pair<string, int>> sortingVector(map.begin(), map.end());

	std::sort(sortingVector.begin(), sortingVector.end(), [](const pair<string, int> &left, const pair<string, int> &right) {
		return left.second > right.second;
	});
	return sortingVector;
}

