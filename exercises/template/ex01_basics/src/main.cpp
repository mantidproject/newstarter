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

bool fileMissing(const std::string &f) {
  // Determine if a file is missing
  std::ifstream test(f);
  return !test.good();
}

bool pair_compare(const std::pair<std::string, int> a, const std::pair<std::string, int> b) {
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
  return false;
}

std::string string_strip(const std::string &word) {
  // Remove invalid characters from a string
  std::string result;
  std::copy_if(word.begin(), word.end(), back_inserter(result), [](char letter){return !ispunct(letter);});
  return result;
}

std::map<std::string, int> add_word(std::map<std::string, int> acc, const std::string &base_word) {
  // Add a single word to the map
  std::string word = string_strip(base_word);
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

std::map<std::string, int> load_file(std::map<std::string, int> &acc, const std::string &f) {
  // Add the words from a file into a map
  std::ifstream infile(f);
  std::istream_iterator<std::string> words(infile);
  std::istream_iterator<std::string> eos; // end of iterator stream

  return accumulate(words, eos, acc, add_word);
}

void print_map_line(const std::pair<std::string, int> value) {
  // print a line out of the map
  std::cout << value.first << "\t" << value.second << std::endl;
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
    std::accumulate(arguments.begin(), arguments.end(), combined, load_file);

  // Sort the map by occurance and word
  auto result = std::vector<std::pair<std::string, int>>(combined.begin(), combined.end());
  sort(result.begin(), result.end(), pair_compare);

  // Display that results
  for_each(result.begin(), result.end(), print_map_line);

  return 0;
}
