#include "main.h"
#include <algorithm>
#include <functional>

/**
 * @brief Creates a results file containing the number of
 * counts of words of >4 characters in a user defined file.
 *
 * @return int 0 on success, >0 otherwise.
 */
int wordCounterInterface() {
  const int MIN_WORD_LENGTH{5};
  // Ask for a file path.
  std::cout << "Please enter the file path:";
  std::string path;
  std::cin >> path;
  std::ifstream fileIn{path.c_str()};

  std::map<std::string, int> counts; // Map to hold the counts of each word.

  // Check if the file exists.
  if (fileIn.is_open()) {
    std::map<std::string, int> counts = countWords(fileIn, MIN_WORD_LENGTH);
    auto sortedByWordCount{sortMap(counts)};
    fileIn.close();
    return writeToFile(sortedByWordCount);
  } else {
    std::cout << "Invalid input path or blank file." << std::endl;
    return 1;
  }
}

/**
 * @brief Format and write a vector of pairs to a file supplied by the user.
 *
 * @param words Vector to write.
 * @return int 0 on success, 1 otherwise.
 */
int writeToFile(std::vector<std::pair<int, std::string>> words) {
  std::cout << "Please enter the output path (paths that do not reach existing "
               "files will create new ones):";
  std::string path;
  std::cin >> path;
  std::ofstream fileOut{path.c_str()};
  if (fileOut.is_open()) {
    // Write headings to the file.
    std::string::size_type maxWordLength = findMaxStringSize(words);
    fileOut << "Word" + std::string(maxWordLength - 4, ' ') + "\tCounts"
            << std::endl;
    // Write the list of words to the file.
    for (auto &wordCountPair : words) {
      fileOut << wordCountPair.second +
                     std::string(maxWordLength - (wordCountPair.second.size()),
                                 ' ') +
                     "\t"
              << wordCountPair.first << std::endl;
    }
    fileOut.close();
    return 0;
  } else {
    std::cout << "Invalid output path." << std::endl;
    return 1;
  }
}

/**
 * @brief Finds the maximum length string in vector of pairs.
 *
 * @param v The vector to check.
 * @return string::size_type The max size.
 */
std::string::size_type
findMaxStringSize(const std::vector<std::pair<int, std::string>> &pairs) {
  std::string::size_type max = 0;
  for (const auto &pair : pairs) {
    if (pair.second.size() > max) {
      max = pair.second.size();
    }
  }
  return max;
}

/**
 * @brief Counts the number of words with >= minWordLength
 * number of characters
 *
 * @param in Stream of words.
 * @param minWordLength The minimum word length to accept.
 * @return std::map<std::string, int> Map of strings and number of occurances.
 */
std::map<std::string, int> countWords(std::ifstream &in,
                                      const int &minWordLength) {
  std::map<std::string, int> words;
  std::string word;
  while (in >> word) {
    cleanWord(word);
    if (word.size() >= minWordLength) {
      ++words[word];
    }
  }
  return words;
}

/**
 * @brief Sorting for pairs based on the first value.
 *
 * @param a First pair to compare.
 * @param b Second pair to compare.
 * @return true First element of a > the first element of b
 * @return false First elemet of a <= first element of b
 */
bool sortInRev(const std::pair<int, std::string> &a,
               const std::pair<int, std::string> &b) {
  return (a.first > b.first);
}

/**
 * @brief Sorts a map into a vector based on the number of counts.
 *
 * @param wordMap The map to sort.
 * @return vector<pair<int, string> > A sorted vector of pairs.
 */
std::vector<std::pair<int, std::string>>
sortMap(const std::map<std::string, int> &wordMap) {
  std::vector<std::pair<int, std::string>> pairs;
  std::pair<int, std::string> pair;
  for (auto const word : wordMap) {
    pair.first = word.second;
    pair.second = word.first;
    pairs.push_back(pair);
  }
  std::sort(pairs.begin(), pairs.end(), sortInRev);
  return pairs;
}

/**
 * @brief Determine if a character is an invalid punctuation character.
 *
 * @param c The character to check.
 * @return true If invalid.
 * @return false if valid or alphanumeric.
 */
bool isBadPunct(char &character) {
  static const std::string badPunct = ".,?'\"!():";
  return !(isalnum(character) || std::find(badPunct.begin(), badPunct.end(),
                                           character) == badPunct.end());
}

/**
 * @brief Convert a string to be all lower case.
 *
 * @param s The string to convert.
 */
void toLowerCase(std::string &str) {
  for (std::string::size_type i = 0; i < str.size(); ++i) {
    str[i] = tolower(str[i]);
  }
}

/**
 * @brief Cleans a word by excluduing invalid punctuation,
 * and changing its case.
 *
 * @param s The string to clean.
 */
void cleanWord(std::string &word) {
  word.erase(std::remove_if(word.begin(), word.end(), isBadPunct), word.end());
  toLowerCase(word);
}

/**
 * @brief Main method to start the program.
 * Simply calls the wordCounter method.
 *
 * @return int 0 on success, any other number otherwise.
 */
int main(int argc, char **argv) { return wordCounterInterface(); }