/**
 * PROGRAM DESCRIPTION:
 *
 * A command line program to read in a text file and give the occurrences of the
 * words.
 *
 **/

// Imports
#include <algorithm>
#include <fstream>
#include <iostream>
#include <iterator>
#include <map>
#include <string>
#include <vector>

// Namespace being used
using namespace std;

/**
 * Code to flip the <string, int> pairs.
 * Code adapted from:
 *https://stackoverflow.com/questions/5056645/sorting-stdmap-using-value?utm_medium=organic&utm_source=google_rich_qa&utm_campaign=google_rich_qa
 **/
template <typename A, typename B> pair<B, A> flipPair(const pair<A, B> &p) {
  return pair<B, A>(p.second, p.first);
}

template <typename A, typename B> multimap<B, A> flipMap(const map<A, B> &src) {
  multimap<B, A> dst;
  transform(src.begin(), src.end(), inserter(dst, dst.begin()), flipPair<A, B>);
  return dst;
}

/**
 *  Split function to take a line of input and return words in line.
 *  From Accelerated C++ Textbook, page 88.
 **/
vector<string> split(const string &s) {
  // Create return object
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  // Process characters
  while (i != s.size()) {
    // Ignore the leading blanks
    while (i != s.size() && isspace(s[i])) {
      ++i;
    }

    // Find end of next word
    string_size j = i;
    while (j != s.size() && !isspace(s[j])) {
      ++j;
    }

    // Found some non-whitespace characters
    if (i != j) {
      ret.push_back(s.substr(i, j - i));
      i = j;
    }
  }

  return ret;
}

/**
 * Main function.
 **/
int main() {
  // Get file name from user and store
  cout << "Please enter the name of the file: " << endl;
  string fileName;
  cin >> fileName;
  ifstream inputFile(fileName);

  // Try to load the file
  if (!inputFile) {
    cerr << "Error, there was a problem opening/reading the file." << endl;
    return -1;
  }

  // Check if file is empty
  // Adapted from
  // https://stackoverflow.com/questions/2390912/checking-for-an-empty-file-in-c
  if (inputFile.peek() == std::ifstream::traits_type::eof()) {
    cerr << "Error, the file was empty!" << endl;
    return -1;
  }

  // To store line of text and words and their counts
  string line;
  map<string, int> wordAndCount;

  // Loop through each line
  while (getline(inputFile, line)) {

    // Get the list of words in each line
    vector<string> words = split(line);

    // Process each word
    for (vector<string>::const_iterator it = words.begin(); it != words.end();
         it++) {
      // Dereference the iterator to get back the word
      string word = *it;

      // Loop through the word
      for (int i = 0; i < word.size(); i++) {
        // Deal with hyphens?
        // Deal with allowed punctuation?

        // Remove all punctuation and white space
        // Convert upper case letters to lowercase letters
        if (ispunct(word[i])) {
          word.erase(i--, 1);
        } else if (isupper(word[i])) {
          word[i] = tolower(word[i]);
        }
      }

      // Only count words that are longer than 4 letters
      if (word.length() > 4) {
        ++wordAndCount[word];
      }
    }
  }

  // Header for output
  cout << "Word"
       << "\t\t"
       << "Usage" << endl;
  cout << "" << endl;

  // Flip the output
  multimap<int, string> dst = flipMap(wordAndCount);

  // Print out the word and its count (to terminal and file)
  ofstream outputFile;
  outputFile.open("results.txt");
  for (multimap<int, string>::const_reverse_iterator it = dst.rbegin();
       it != dst.rend(); ++it) {
    cout << it->second << "\t\t" << it->first << endl;
    outputFile << it->second << "\t\t" << it->first << endl;
  }
  cout << "Finished writing results to 'results.txt'..." << endl;
  outputFile.close();

  return 0;
}
