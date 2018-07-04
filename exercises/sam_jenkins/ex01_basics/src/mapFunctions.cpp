#include <unordered_map>
#include <sstream>
#include "stringManip.h"
#include <vector>


using std::string; using std::unordered_map; using std::vector;

unordered_map<string, int> countof(const string& input)
{
	unordered_map<string, int>wordtable;
	std::istringstream iss(input);

	auto i = input.begin();
	while (i != input.end()) {

		i = find_if(i, input.end(), not_space);
		auto j = find_if(i, input.end(), space);
		if (i != input.end()) {
			string current(i, j);
			strip_string(current);
			if (current.length() > 4) {
				++wordtable[current];
			}
			i = j;
		}
	}
	return wordtable;
}

vector<std::pair<string, int>> mapToVector(unordered_map<string, int>map)
{
	vector<std::pair<string, int>> sortingVector(map.begin(), map.end());
	std::sort(sortingVector.begin(), sortingVector.end(), [](auto &left, auto&right) {
		return left.second > right.second; });
	return sortingVector;
}
