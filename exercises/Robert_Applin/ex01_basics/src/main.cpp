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

using WordCountPair = std::pair<std::string, std::size_t>;
using WordCount = std::vector<WordCountPair>;

/**
 * function finds the end point of a word.
 * @params Iterators representing the start and end points of an
 *         iteration. The characters used to split up each word.
 * @return An iterator pointing to the next letter contained
 *         in the supplied string.
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
 * function finds the starting point of a word.
 * @params Iterators representing the start and end points of an
 *         iteration. The characters used to split up each word.
 * @return An iterator pointing to the next letter not
 *         contained in the supplied string.
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
 * function separates each word, placing them in a vector of strings.
 * @params Iterators representing the start and end points of an
 *         iteration. The characters used to split up each word.
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
 * function identifies which word has a higher count.
 * @params Two std::pairs containing a word and their count
 * @return A true if count1 is larger than count2
 */
bool compareCounts(const WordCountPair &count1, const WordCountPair &count2) {
  return count1.second > count2.second;
}

/**
 * function removes any words shorter than five from the vector
 * @params A vector of words
 * @return void
 */
void removeShorterThanFive(std::vector<std::string> &strings) {
  auto it =
      std::remove_if(strings.begin(), strings.end(),
                     [](const std::string str) { return str.length() < 5; });
  // Remove invalid indices
  strings.erase(it, strings.end());
}

/**
 * function transforms a string to lower case
 * @params A string representing a word
 * @return A string transformed to lower case
 */
std::string toLower(std::string str) {
  std::transform(str.begin(), str.end(), str.begin(),
                 [](const char str2) { return std::tolower(str2); });
  return str;
}

/**
 * function adds one to the count for a string.
 * @params A map containing each word and their count
 * @return void
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
 * function records the number of occurences of each word.
 * @params A vector of words and a map containing each word and their count
 * @return void
 */
void countWords(const std::vector<std::string> &substrings,
                std::unordered_map<std::string, std::size_t> &count) {
  for (auto const &str : substrings)
    addToCount(count, str);
}

/**
 * function splits the string into each word, removes short words and
 * changes each word to lower case before counting the number of occurences.
 * @params The string to be word counted, the characters each word will be split
 *         around and a map containing each word and their count
 * @return void
 */
void countWords(const std::string &str, const std::string &delimiters,
                std::unordered_map<std::string, std::size_t> &count) {
  auto words = splitBy(str.begin(), str.end(), delimiters);
  removeShorterThanFive(words);
  for (auto &word : words) {
    word = toLower(word);
  }
  countWords(words, count);
}

/**
 * function gets each line of the provided file
 * @params The istream opened to read the file and the characters each word
 *         will be split around.
 * @return A vector pair containing each word paired to their usage count.
 */
WordCount countWords(std::istream &start, const std::string &delimiters) {
  std::unordered_map<std::string, std::size_t> count;
  for (std::string line; std::getline(start, line);)
    countWords(line, delimiters, count);
  return WordCount(count.begin(), count.end());
}

/**
 * function attempts to access the provided file
 * @params The file name, and the characters each word will be split around.
 * @return A vector pair containing each word paired to their usage count.
 */
WordCount countWordsInFile(const std::string &filename,
                           const std::string &delimiters) {
  std::ifstream filestream(filename);
  if (!filestream) {
    filestream.close();
    throw std::runtime_error("Error occured when attempting to load file: " +
                             filename);
  }

  auto wordCounts = countWords(filestream, delimiters);
  filestream.close();
  return wordCounts;
}

/**
 * function sorts the words in order of their count
 * @params The file name, and the characters each word will be split around.
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
 * function formats and outputs each word along with their count
 * @params A vector pair containing each word and their count, the output
 *         stream, and the number of charaters to be used for each output line.
 * @return void
 */
void outputWordCount(const WordCount &wordCounts, std::ostream &output,
                     std::size_t wordStreamSize, std::size_t countStreamSize) {
  for (const auto &count : wordCounts)
    output << std::setw(wordStreamSize) << count.first
           << std::setw(countStreamSize) << count.second << '\n';
}

/**
 * function gets the file name and outputs Word and Usage headings
 * @params The input stream, the output stream, the characters each word will
 *         be split around, and the number of charaters to be used for each
 *         output line.
 * @return void
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
