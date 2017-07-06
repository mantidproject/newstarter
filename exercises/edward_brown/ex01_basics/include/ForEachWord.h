#include "DiscardWhile.h"
#include "TakeWhile.h"
#include "WordCharPredicates.h"

/** Calls the DoIt action on all words found in the range [Begin, End).
 *  Here a word is a sequence of one or more whitespace characters terminated
 *  by End or a whitespace character.
 *
 *  @param Begin The const_iterator marking the begining of the range in which
 * to find words.
 *  @param End The const_iterator marking the end of the range in which to find
 * words.
 *  @param DoIt A callable object to be called for each word found in the range
 * [Begin, End).
 */
template <typename ConstCharInputIterator, typename Action>
void forEachWord(ConstCharInputIterator Begin, ConstCharInputIterator End,
                 Action DoIt) {
  auto Current = Begin;
  while (Current != End) {
    auto WordPositionPair = takeWhile(Current, End, &isWordChar);
    DoIt(std::move(WordPositionPair.first));
    Current = WordPositionPair.second;
    Current = discardWhile(Current, End, &isWhitespaceChar);
  }
}
