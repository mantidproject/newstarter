#include <unordered_map>
#include "ForEachWord.h"
#include "Punctuation.h"
#include "ToLowerCase.h"

bool isWord(std::string const &word) {
  auto constexpr MINIMUM_WORD_LENGTH = 4;
  return word.size() > MINIMUM_WORD_LENGTH;
}

template <typename ConstCharInputIterator>
std::unordered_map<std::string, int>
makeWordFrequencyMap(ConstCharInputIterator begin, ConstCharInputIterator end) {
  auto wordFrequencyMap = std::unordered_map<std::string, int>();
  forEachWord(
      begin, end, [&wordFrequencyMap](std::string WordCandidate) -> void {
        if (isWord(WordCandidate)) {
          wordFrequencyMap[toLowerCase(stripPunctuation(WordCandidate))]++;
        }
      });
  return std::move(wordFrequencyMap);
}
