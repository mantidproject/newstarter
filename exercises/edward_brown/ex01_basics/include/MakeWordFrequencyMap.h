#include "ForEachWord.h"
#include "Punctuation.h"
#include "ToLowerCase.h"
#include <unordered_map>

/** A predicate which determines if CandidateWord is a word for the purposes of
 *  word frequency analysis.
 *
 *  @param CandidateWord The candidate to check.
 *  @return True if CandidateWord is a 'word' false if not.
 */
bool isWord(std::string const &CandidateWord) {
  auto constexpr MinimumWordLength = 4;
  return CandidateWord.size() > MinimumWordLength;
}

/** Creates a map from strings containing words found in the range [Begin, End)
 * to integer values denoting the corresponding number of occurences in said
 * range.
 *
 *  This analysis is case and punctuation insensitive. Words with a length
 * shorter than four characters are ignored.
 *
 *  @param Begin The const_iterator marking the beginning of the range to search
 * for words.
 *  @param End The const_iterator marking the end of the range to search for
 * words.
 *  @return The map built from the word frequency analysis performed.
 */
template <typename ConstCharInputIterator>
std::unordered_map<std::string, int>
makeWordFrequencyMap(ConstCharInputIterator begin, ConstCharInputIterator end) {
  auto wordFrequencyMap = std::unordered_map<std::string, int>();
  forEachWord(
      begin, end, [&wordFrequencyMap](std::string WordCandidate) -> void {
        WordCandidate = stripPunctuation(WordCandidate);
        if (isWord(WordCandidate)) {
          wordFrequencyMap[toLowerCase(stripPunctuation(WordCandidate))]++;
        }
      });
  return std::move(wordFrequencyMap);
}
