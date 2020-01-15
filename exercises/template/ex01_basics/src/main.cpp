/**
 * Skeleton main routine
 */

#include <algorithm>
#include <ctype.h>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>

namespace {

  bool fileMissing(const std::string &f) {
    // Determine if a file is missing
    std::ifstream test(f);
    return !test.good();
  }

  void stringStrip(std::string &word) {
    // Remove invalid characters from a string
    word.erase(std::remove_if(word.begin(), word.end(),
			      [](char letter){return ispunct(letter);}),
	       word.end());
  }

  std::map<std::string, int> addWord(std::map<std::string, int> acc, std::string word) {
    // Add a single word to the map
    stringStrip(word);
    if (word.size() < 4) {
      return acc;
    }
    std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    if (acc.count(word)) {
      acc[word] += 1;
    } else {
      acc[word] = 1;
  }
    return acc;
  }

  std::map<std::string, int> loadFile(std::map<std::string, int> &acc, const std::string &f) {
    // Add the words from a file into a map
    std::ifstream infile(f);
    std::istream_iterator<std::string> words(infile);
    std::istream_iterator<std::string> eos; // end of iterator stream

    return accumulate(words, eos, acc, addWord);
  }
}


int main(const int argc, const char **argv) {
  if (argc <= 1) {
    std::cout << "Missing file name" << std::endl;
    return -1;
  }

  std::vector<std::string> arguments(argv + 1, argc + argv);

  // Make sure that all the files are present
  auto missing = std::find_if(arguments.begin(), arguments.end(), fileMissing);

  if (missing != arguments.end()) {
    std::cout << "Cannot find file " << *missing << std::endl;
    return -1;
  }

  // Read all the files into a map
  std::map<std::string, int> combined;
  combined =
    std::accumulate(arguments.begin(), arguments.end(), combined, loadFile);

  // Sort the map by occurance and word
  auto result = std::vector<std::pair<std::string, int>>(combined.begin(), combined.end());
  sort(result.begin(), result.end(), [](const std::pair<std::string, int> &a, const std::pair<std::string, int> &b){
  // Sort pairs descending by integer value, then ascending by string value.
  if (a.second > b.second) {
    return true;
  }
  if (a.second < b.second) {
    return false;
  }
  if (a.first < b.first) {
    return true;
  }
  return false;});

  // Display that results
  for_each(result.begin(), result.end(),
	   [](const std::pair<std::string, int> value){
	     std::cout << value.first << "z" << value.second << std::endl;});

  return 0;
}
