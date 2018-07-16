#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <algorithm>
#include <cctype>
#include <vector>
#include <iomanip>
#include <utility>


using std::string; using std::max; using std::find_if_not;
using std::ifstream; using std::fstream;
using std::getline; using std::map; using std::pair; using std::transform;
 using std::endl; using std::vector;
using std::cout; using std::find; using std::ofstream;
using std::find_if; using std::vector; using std::setw;

bool pass(string str, string sample, size_t limit);

int main(){
	// vector of pairs to sort
	vector < pair < string, int > > v;

    // max word length
    size_t size = 0;

    //write each word into line
    string line;

    // create input file object
    ifstream infile("Holmes.txt");

	// create output file
	ofstream outfile("Holmes Counter.txt");

    // map to store word occurences
    map<string, int> occurences;
    
    // open file for reading
    if (infile.is_open()){

        // read line
        while(getline(infile, line)){
            
            // iterator to loop through each line
            auto i = line.begin();

            while(i != line.end()){
				
                // ignore leading blanks
				i = find_if_not(i, line.end(), ::isspace);

				// ignore leading characters
				i = find_if(i, line.end(), ::isalpha);

				// if line is all whitespaces or has reached the end
				if (i == line.end()) {
					break;
				}

                // find end of next word
                auto j = find_if(i, line.end(), ::isspace);

                // copy the characters in [i, j) and increment the counter
                // or add to occurences after checking conditions
				if (i != line.end()) {

					// word
					string word = string(i, j);

					// make word lowercase
					transform(word.begin(), word.end(), word.begin(), ::tolower);

					// remove non alphabetic characters at the end of word
					while (!isalpha(word.back())) {
						word = word.substr(0, word.size() - 1);
					}
				
                    // check conditions and add to occurence
                    if (!pass(word, ".,?'\"!():", 4)){
						i = j;
                        continue;
                    } else{
                    ++occurences[word];
                    size = max(size, word.size());
                    }
                }
				// make end of last the start of first
				i = j;
            }
        }
		infile.close();
    
    }else{
        cout << "File could not be opened" << endl;
    }

	// sort occurences using vector of pairs (v)
	for (auto i : occurences) {
		v.push_back(i);
	}

	sort(v.begin(), v.end(), 
		[](pair <string, int> a, pair <string, int> b){
			return a.second > b.second;
		});

    // write the occurences from vector of pairs to a file
	outfile << "Word" << setw(size - 2) << "Occurence" << setw(4) << endl;
    for(auto i : v){
        outfile << i.first << setw(size - i.first.size() + 2) << i.second << setw(4) << endl;
    }

	// close outfile
	outfile.close();

    return 0;
}

// check if a character in sample is in word
// and see if the number of characters is > limit
bool pass(string str, string sample, size_t limit) {

	if (str.size() > limit) {
		for (auto i : str) {
			if (sample.find(i) && !::isalpha(i)) {
				return false;
			}
		}
		return true;
	}
	else {
		return false;
	}
}
