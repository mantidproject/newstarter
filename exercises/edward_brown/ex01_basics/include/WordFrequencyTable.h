#ifndef EX1_WORD_FREQUENCY_TABLE
#define EX1_WORD_FREQUENCY_TABLE
#include <algorithm>
#include <string>
#include <utility>
#include <vector>

using WordFrequencyPair = std::pair<std::string, int>;
using WordFrequencyTable = std::vector<WordFrequencyPair>;

/** Converts word frequency pairs in the range [Begin, End) into a vector of
 *  pairs sorted by frequency from highest to lowest.
 *
 *  @param Begin The const_iterator which marks the begining of the range of
 * pairs.
 *  @param End The const_iterator which marks the end of the range of pairs.
 *  @return The created vector.
 */
template <typename ConstWordFrequencyPairInputIterator>
WordFrequencyTable
makeOrderedWordFrequencyTable(ConstWordFrequencyPairInputIterator Begin,
                              ConstWordFrequencyPairInputIterator End) {
  auto table = WordFrequencyTable(Begin, End);
  std::sort(table.begin(), table.end(),
            [](WordFrequencyPair const &A, WordFrequencyPair const &B) -> bool {
              return A.second > B.second;
            });
  return std::move(table);
}

/** Prints a padded word frequency table to the output stream.
 *  @param OutputStream The output stream to print to.
 *  @param Table The table to print.
 *  @return The output stream that was printed to.
 */
std::ostream &operator<<(std::ostream &OutputStream,
                         WordFrequencyTable const &Table);

/** Prints a padded word frequency row to the output stream.
 *  @param OutputStream The output stream to print to.
 *  @param Row The row to print.
 *  @return The output stream that was printed to.
 */
std::ostream &operator<<(std::ostream &OutputStream,
                         WordFrequencyPair const &Row);
#endif // EX1_WORD_FREQUENCY_TABLE
