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
  const int MIN_WORD_LENGTH = 5;
  // Ask for a file path.
  std::cout << "Please enter the file path:";
  std::string path;
  std::cin >> path;
  std::ifstream fileIn{path.c_str()};

  std::map<std::string, int> counts; // Map to hold the counts of each word.

  // Check if the file exists.
  if (fileIn.is_open()) {
    std::map<std::string, int> counts = countWords(fileIn, MIN_WORD_LENGTH);
    std::vector<std::pair<int, std::string>> sortedByWordCount{sortMap(counts)};
    fileIn.close();
    std::cout
        << "Please enter the output path (paths that do not reach existing "
           "files will create new ones):";
    std::cin >> path;
    std::ofstream fileOut{path.c_str()};
    if (fileOut.is_open()) {
      // Write headings to the file.
      std::string::size_type maxWordLength =
          findMaxStringSize(sortedByWordCount);
      fileOut << "Word" + std::string(maxWordLength - 4, ' ') + "\tCounts"
              << std::endl;
      // Write the list of words to the file.
      for (auto &wordCountPair : sortedByWordCount) {
        fileOut << wordCountPair.second +
                       std::string(
                           maxWordLength - (wordCountPair.second.size()), ' ') +
                       "\t"
                << wordCountPair.first << std::endl;
      }
      fileOut.close();
      return 0;
    } else {
      std::cout << "Invalid output path." << std::endl;
    }
  } else {
    std::cout << "Invalid input path or blank file." << std::endl;
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
  for (const std::pair<int, std::string> &p : pairs) {
    if (p.second.size() > max) {
      max = p.second.size();
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
  std::string s;
  while (in >> s) {
    cleanWord(s);
    if (s.size() >= minWordLength) {
      ++words[s];
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
  std::pair<int, std::string> p;
  for (auto i = wordMap.begin(); i != wordMap.end(); ++i) {
    p.first = i->second;
    p.second = i->first;
    pairs.push_back(p);
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
bool isBadPunct(char &c) {
  static const std::string badPunct = ".,?'\"!():";
  return !(isalnum(c) ||
           std::find(badPunct.begin(), badPunct.end(), c) == badPunct.end());
}

/**
 * @brief Convert a string to be all lower case.
 *
 * @param s The string to convert.
 */
void toLowerCase(std::string &s) {
  for (std::string::size_type i = 0; i < s.size(); ++i) {
    s[i] = tolower(s[i]);
  }
}

/**
 * @brief Cleans a word by excluduing invalid punctuation,
 * and changing its case.
 *
 * @param s The string to clean.
 */
void cleanWord(std::string &s) {
  s.erase(std::remove_if(s.begin(), s.end(), isBadPunct), s.end());
  toLowerCase(s);
}

/**
 * @brief Main method to start the program.
 * Simply calls the wordCounter method.
 *
 * @return int 0 on success, any other number otherwise.
 */
int main(int argc, char **argv) { return wordCounterInterface(); }