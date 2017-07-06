#include <string>
#include <vector>
#include <utility>
#include <algorithm>

using WordFrequencyPair = std::pair<std::string, int>;
using WordFrequencyTable = std::vector<WordFrequencyPair>;

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

std::ostream& operator<<(std::ostream& OutputStream, WordFrequencyTable const& Table); 
std::ostream& operator<<(std::ostream& OutputStream, WordFrequencyPair const& Row); 

