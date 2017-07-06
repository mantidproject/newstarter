#include "DiscardWhile.h"
#include "TakeWhile.h"
#include "WordCharPredicates.h"

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
