/**
 * Skeleton main routine
 */

#include <algorithm>
#include <cctype>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using WordCount = std::vector<std::pair<std::string, std::size_t>>;

/**
 * @return An iterator pointing to the next letter contained
 *         in the supplied set.
 */
std::string::const_iterator
findNextCharacter(std::string::const_iterator fromIterator,
                  std::string::const_iterator toIterator,
                  const std::string &characters) {
  for (auto it = fromIterator; it < toIterator; ++it) {
    if (characters.find(*it) != std::string::npos)
      return it;
  }
  return toIterator;
}

/**
 * @return An iterator pointing to the next letter not
 *         contained in the supplied set.
 */
std::string::const_iterator
findNextNotCharacter(std::string::const_iterator fromIterator,
                     std::string::const_iterator toIterator,
                     const std::string &characters) {
  for (auto it = fromIterator; it < toIterator; ++it) {
    if (characters.find(*it) == std::string::npos)
      return it;
  }
  return toIterator;
}

/**
 * @return A vector of sub strings split around delimiters
 */
std::vector<std::string> splitBy(std::string::const_iterator fromIterator,
                                 std::string::const_iterator toIterator,
                                 const std::string &delimiters) {
  std::vector<std::string> substrings;
  auto iter = findNextNotCharacter(fromIterator, toIterator, delimiters);

  while (iter != toIterator) {
    const auto nextIter = findNextCharacter(iter, toIterator, delimiters);
    substrings.emplace_back(iter, nextIter);
    iter = findNextNotCharacter(nextIter, toIterator, delimiters);
  }
  return substrings;
}

/**
 * @return A true if count1 is larger than count2
 */
bool compareCounts(const std::pair<std::string, std::size_t> &count1,
                   const std::pair<std::string, std::size_t> &count2) {
  return count1.second > count2.second;
}

/**
 * @return True if the string is shorter than 5 characters
 */
bool isShorterThanFive(const std::string &str) { return str.length() < 5; }

/**
 * Removes any words shorter than five from the vector
 */
void removeShorterThanFive(std::vector<std::string> &strings) {
  auto it = std::remove_if(strings.begin(), strings.end(), isShorterThanFive);
  // Remove invalid indices
  strings.erase(it, strings.end());
}

/**
 * @return A string transformed to lower case
 */
std::string toLower(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(), std::tolower);
  return str;
}

/**
 * Add one to the count for a string, or creates a new mapping for a
 * new string and sets its count to one.
 */
void addToCount(std::unordered_map<std::string, std::size_t> &count,
                const std::string &str) {
  auto it = count.find(str);
  if (it == count.end())
    count[str] = 1;
  else
    ++it->second;
}

/**
 * Loops through the strings in substrings and records the
 * number of occurences for each string.
 */
void countWords(const std::vector<std::string> &substrings,
                std::unordered_map<std::string, std::size_t> &count) {
  for (auto const &str : substrings)
    addToCount(count, str);
}

/**
 * Splits the string into each word, removes short words and changes
 * each word to lower case before counting the number of occurances.
 */
void countWords(const std::string &str, const std::string &delimiters,
                std::unordered_map<std::string, std::size_t> &count) {
  auto words = splitBy(str.begin(), str.end(), delimiters);
  removeShorterThanFive(words);
  std::transform(words.begin(), words.end(), words.begin(), toLower);
  countWords(words, count);
}

/**
 * @return A vector pair containing each word paired to their usage count.
 */
WordCount countWords(std::istream &start, const std::string &delimiters) {
  std::unordered_map<std::string, std::size_t> count;
  for (std::string line; std::getline(start, line);)
    countWords(line, delimiters, count);
  return std::vector<std::pair<std::string, std::size_t>>(count.begin(),
                                                          count.end());
}

/**
 * @return A vector pair containing each word paired to their usage count.
 */
WordCount countWordsInFile(const std::string &filename,
                           const std::string &delimiters) {
  std::ifstream filestream(filename);
  if (!filestream)
    throw std::runtime_error("Error occured when attempting to load file: " +
                             filename);

  auto wordCounts = countWords(filestream, delimiters);
  filestream.close();
  return wordCounts;
}

/**
 * @return A vector pair containing each word sorted from highest usage to
 *         lowest usage.
 */
WordCount countWordsInFileAndSort(const std::string &filename,
                                  const std::string &delimiters) {
  auto wordCount = countWordsInFile(filename, delimiters);
  std::sort(wordCount.begin(), wordCount.end(), compareCounts);
  return wordCount;
}

/**
 * Formats and outputs each word with their usage
 */
void outputWordCount(const WordCount &wordCounts, std::ostream &output,
                     std::size_t wordStreamSize, std::size_t countStreamSize) {
  for (const auto &count : wordCounts)
    output << std::setw(wordStreamSize) << count.first
           << std::setw(countStreamSize) << count.second << '\n';
}

/**
 * Gets the file name and outputs Word and Usage headings
 */
void getFileAndOutputWordCount(std::istream &input, std::ostream &output,
                               const std::string &delimiters,
                               std::size_t wordStreamSize,
                               std::size_t countStreamSize) {
  std::string filename;
  input >> filename;
  auto wordCount = countWordsInFileAndSort(filename, delimiters);
  output << std::setw(wordStreamSize) << "Word" << std::setw(countStreamSize)
         << "Usage\n";
  outputWordCount(wordCount, output, wordStreamSize, countStreamSize);
}

int main(int argc, char *argv[]) {
  const std::string delimiters = ".!, ?\'\"()-:;\\";

  std::cout << "Provide a filename:\n";
  try {
    getFileAndOutputWordCount(std::cin, std::cout, delimiters, 14, 15);
  } catch (const std::runtime_error &ex) {
    std::cout << ex.what();
  }
  std::cout << std::endl;
}
