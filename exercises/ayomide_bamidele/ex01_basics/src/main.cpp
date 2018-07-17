#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/**
 * Checks if a string is at least sizeLimit long and only has characters in
 * allowedPunctuations
 *
 * @param word a string
 * @param allowedPunctuations a string of not alphanumeric characters
 * @param siseLimit size_t integer
 * @return returns false if word has less than sizeLimit characters or if a non
 * alphanumeric character in word is in punctuations
 */
bool checkSizeAndPunctuation(const string &word,
                             const string &allowedPunctuations,
                             const size_t &sizeLimit) {

  if (word.size() <= sizeLimit) {
    return false;
  }

  for (const auto &character : word) {
    if (allowedPunctuations.find(character) && !isalpha(character)) {
      return false;
    }
  }
  return true;
}

/**
 * Checks if the a character is whitespace or non alphanumeric
 *
 * @param character a character type
 * @return returns true if character is whitespace or non alphanumeric
 */
bool isSpaceOrPunctuation(char character) {

  if (isspace(character) || !isalpha(character))
    return true;

  return false;
}

/**
 * Takes a map of <string, int> and returns a vector according to the values in
 * the map.
 *
 * @param map a map of <string, int>
 * @return returns the sorted vector of pair<string, int> according to the
 * values in the map
 */
vector<pair<string, int>> maptoVecSorter(const map<string, int> &map) {

  // vector of pairs to sort
  vector<pair<string, int>> sortVector(map.begin(), map.end());

  sort(sortVector.begin(), sortVector.end(),
       [](pair<string, int> a, pair<string, int> b) {
         return a.second > b.second;
       });

  return sortVector;
}

/**
 * Takes an output file and a vector of <string, int> pairs and writes the key
 * value pairs to the file
 *
 * @param outfile output file
 * @param vecPairs vector of <string, int> pairs
 * @param maxWordLength length of longest word, used to determine the space used
 * in output stream
 * @return returns 0 if successful
 */

int writeToFile(ostream &outfile, const vector<pair<string, int>> &vecPairs,
                int maxWordLength) {

  outfile << "Word" << setw(maxWordLength - 2) << "Occurrence" << setw(4)
          << endl;

  for (const auto &occurencePair : vecPairs) {
    outfile << occurencePair.first
            << setw(maxWordLength - occurencePair.first.size() + 2)
            << occurencePair.second << setw(4) << endl;
  }

  return 0;
}

int main() {
  const auto allowedPunctuations{".,?'\"!():"};
  const int wordLimit = 4;
  size_t maxWordLength = 0;
  ifstream inFile("Holmes.txt");
  ofstream outFile("Holmes Counter.txt");
  map<string, int> occurences;
  string lineOfText;

  if (inFile.is_open()) {
    while (getline(inFile, lineOfText)) {
      transform(lineOfText.begin(), lineOfText.end(), lineOfText.begin(),
                tolower);
      auto lineIterator = lineOfText.begin();
      while (lineIterator != lineOfText.end()) {

        // start of first word
        lineIterator =
            find_if_not(lineIterator, lineOfText.end(), isSpaceOrPunctuation);

        // start of next word
        auto nextWordIterator =
            find_if(lineIterator, lineOfText.end(), isSpaceOrPunctuation);

        // add word to occurrences
        if (lineIterator != lineOfText.end()) {
          auto word = string(lineIterator, nextWordIterator);

          if (!checkSizeAndPunctuation(word, allowedPunctuations, wordLimit)) {
            lineIterator = nextWordIterator;
            continue;
          } else {
            ++occurences[word];
            maxWordLength = max(maxWordLength, word.size());
          }
        }
        lineIterator = nextWordIterator;
      }
    }
    inFile.close();
  } else {
    cout << "File could not be opened" << endl;
  }

  auto sortedVector = maptoVecSorter(occurences);
  writeToFile(outFile, sortedVector, maxWordLength);

  outFile.close();

  return 0;
}
