
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
#include <iterator>

using namespace std;

typedef pair<string, int> countpair;

//checks if character is punctuation
bool ispunc(const char& c) {
	static const string punc = ".,?'\"!() : ";
	return find(punc.begin(), punc.end(), c) == punc.end();
}

bool compare(const countpair& p1, const countpair& p2) {
	return p1.second > p2.second;
}

int main(int argc, char* argv[]) {

	ifstream in(argv[1]);
	string s;
	map<string, int> counts;

	//check each word for punctuation and length
	while (!in.eof()) {
		char c;
		in.get(c);
		c = tolower(c);
		if (!isspace(c) && ispunc(c)) {
			s.push_back(c);
		}
		else {
			if (s.size() >= 4) ++counts[s];
			s.clear();
		}
	}

	//puts the map into a vetor and sorts it
	vector<countpair> sortvec;
	copy(counts.begin(), counts.end(), back_inserter(sortvec));
	sort(sortvec.begin(), sortvec.end(), compare);

	//prints out values in order of usage
	int vecsize = sortvec.size();
	for (int i = 0; i < vecsize; ++i)
		cout << sortvec[i].first << " : " << sortvec[i].second << endl;
	return 0;


}