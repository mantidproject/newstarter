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
 * @return returns false if word has less than sizeLimit characters or if a non
 * alphanumeric character in word is in punctuations
 */
bool checkSizeAndPunctuation(const string &word) {
  const string allowedPunctuations(".,?'\"!():");
  const size_t sizeLimit = 4;
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
  return (isspace(character) || !isalpha(character));
}

/**
 * Takes a map of <string, int> and returns a vector sorted according to the
 * values in the map.
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
 * @param outFile output file
 * @param vecPairs vector of <string, int> pairs
 * @param maxWordLength length of longest word, used to determine the space used
 * in output stream
 * @return returns 0 if successful
 */

int writeToFile(ofstream &outFile, const vector<pair<string, int>> &vecPairs,
                size_t maxWordLength) {

  outFile << "Word" << setw(maxWordLength) << "Occurrence" << endl;

  for (const auto &occurencePair : vecPairs) {
    outFile << occurencePair.first
            << setw(maxWordLength - occurencePair.first.size())
            << occurencePair.second << endl;
  }

  outFile.close();
  return 0;
}

int main() {
  size_t maxWordLength = 0;
  ifstream inFile("Holmes.txt");
  ofstream outFile("Holmes Counter.txt");
  map<string, int> occurences;
  string lineOfText;

  if (inFile.is_open()) {
    while (getline(inFile, lineOfText)) {
      transform(lineOfText.begin(), lineOfText.end(), lineOfText.begin(),
                ::tolower);
      auto lineIterator = lineOfText.begin();
      while (lineIterator != lineOfText.end()) {

        // start of first word
        lineIterator =
            find_if_not(lineIterator, lineOfText.end(), isSpaceOrPunctuation);

        // start of next word
        auto nextWordIterator =
            find_if(lineIterator, lineOfText.end(), isSpaceOrPunctuation);

        auto word = string(lineIterator, nextWordIterator);

        // add word to occurrences
        if (lineIterator == lineOfText.end() ||
            !checkSizeAndPunctuation(word)) {
          lineIterator = nextWordIterator;
          continue;
        } else {
          ++occurences[word];
          maxWordLength = max(maxWordLength, word.size());
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

  return 0;
}
