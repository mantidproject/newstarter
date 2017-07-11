#ifndef EX1_DISCARD_WHILE
#define EX1_DISCARD_WHILE
#include <algorithm>
/** Performs a linear search over the range [Begin, End) for a character c
 *  such that ShouldDiscard(c) is false returning the first occurence found.
 * Otherwise, if no character c is found then End will be returned.
 *
 *  @param Begin The const_iterator marking the begining of the range to search.
 *  @param End The const_iterator one past the end of the range to search.
 *  @param ShouldDiscard A callable object which returns true when the iteration
 * should continue else false if it should stop.
 *
 *  @return An iterator pointing to the first occurence or the end of search
 * range if no such occurence exists.
 */
template <typename ConstCharInputIterator, typename CharPredicate>
ConstCharInputIterator discardWhile(ConstCharInputIterator Begin,
                                    ConstCharInputIterator End,
                                    CharPredicate ShouldDiscard) {
  return std::find_if_not(Begin, End, ShouldDiscard);
}
#endif // EX1_DISCARD_WHILE
