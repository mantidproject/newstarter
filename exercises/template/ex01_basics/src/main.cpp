/**
 * Skeleton main routine
 */

#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

bool fileMissing(string f) {
  return !boost::filesystem::exists(f);
}


map<string, int> load_file(map<string, int> acc, string f) {
  ifstream infile(f);
  string word;
  while (infile >> word) {
    // transform(word.begin(), word.end(), word.begin(), tolower);
    if (acc.count(word)) {
	acc[word] += 1;
    } else{
	acc[word] = 1;
    }
  }
  return acc;
}

int main(int argc, char **argv)
{
  if(argc <= 1) {
    cout << "Missing file name" << endl;
    return -1;
  }

  vector<string> arguments(argv+1, argc+argv);

  auto missing = find_if(arguments.begin(), arguments.end(), fileMissing);

  if (missing != arguments.end()) {
    cout << "Cannot find file " << *missing << endl;
    return -1;
  }

  map<string, int> combined;
  combined = accumulate(arguments.begin(), arguments.end(), combined, load_file);

  for (auto i : combined) {
    cout << i.first << " ==> " << i.second << endl;
  }

  return 0;
}
