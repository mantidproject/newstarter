/**
 * Skeleton main routine
 */

#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>

using namespace std;

bool fileMissing(string f) {
  //Determine if a file is missing
  ifstream test(f);
  return !test.good();
}

bool valid_char(char x) {
  //Determine if a character is common punctuation
  switch (x) {
  case '.':
  case '\'':
  case '"':
  case '?':
  case ',':
  case '!':
  case '(':
  case ')':
  case '`':
  case ':':
  case '_':
    return false;
  default:
    return true;
  }
}

bool pair_compare(pair<string, int>a, pair<string, int> b) {
  // Sort pairs descending by integer value, then ascending by string value.
  if (a.second > b.second) { return true; }
  if (a.second < b.second) { return false; }
  if (a.first < b.first) { return true; }
  return false;
}

string string_strip(string word){
  //Remove invalid characters from a string
  string result;
  copy_if(word.begin(), word.end(), back_inserter(result), valid_char);
  return result;
}


map<string, int> add_word(map<string, int> acc, string word) {
  // Add a single word to the map
  word = string_strip(word);
  if (word.size() < 4) {
    return acc;
  }
  transform(word.begin(), word.end(), word.begin(), ::tolower);
  if (acc.count(word)) {
    acc[word] += 1;
  } else{
    acc[word] = 1;
  }
  return acc;
}


map<string, int> load_file(map<string, int> acc, string f) {
  //Add the words from a file into a map
  ifstream infile(f);
  istream_iterator<string> words(infile);
  istream_iterator<string> eos; //end of iterator stream

  return accumulate(words, eos, acc, add_word);
}

void print_map_line(pair<string, int> value) {
  //print a line out of the map
  cout << value.first << "\t" << value.second << endl;
}

int main(int argc, char **argv)
{
  if(argc <= 1) {
    cout << "Missing file name" << endl;
    return -1;
  }

  vector<string> arguments(argv+1, argc+argv);

  // Make sure that all the files are present
  auto missing = find_if(arguments.begin(), arguments.end(), fileMissing);

  if (missing != arguments.end()) {
    cout << "Cannot find file " << *missing << endl;
    return -1;
  }

  // Read all the files into a map
  map<string, int> combined;
  combined = accumulate(arguments.begin(), arguments.end(), combined, load_file);

  // Sort the map by occurance and word
  auto result = vector<pair<string, int>>(combined.begin(), combined.end());
  sort(result.begin(), result.end(), pair_compare);

  // Display that results
  for_each(result.begin(), result.end(), print_map_line);

  return 0;
}
