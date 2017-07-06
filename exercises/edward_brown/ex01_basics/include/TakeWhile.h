#ifndef EX1_TAKE_WHILE
#define EX1_TAKE_WHILE
#include <sstream>
#include <utility>

/** Builds a substring s of the range [Begin, End) such that s contains
 *  the characters between the start of the range and the character c where
 *  c is the first occurence of a character such that ShouldTake(c) is false.
 *  If no such character exists then the substring s will we equal to the string
 *  of all characters in the range [Begin, End)
 *
 *  @param Begin The const_iterator marking the begining of the range to be
 *  searched for c.
 *  @param End The const_iterator marking the end of the range to be
 *  searched for c.
 *  @param ShouldTake A callable object which returns a pair containing the
 *  substring s and the const_iterator which points to c.
 */
template <typename ConstCharInputIterator, typename CharPredicate>
std::pair<std::string, ConstCharInputIterator>
takeWhile(ConstCharInputIterator Begin, ConstCharInputIterator End,
          CharPredicate ShouldTake) {
  auto WordStream = std::stringstream();
  auto Current = Begin;
  while (Current != End && ShouldTake(*Current)) {
    WordStream << *Current;
    Current++;
  }
  return std::make_pair(WordStream.str(), Current);
}
#endif // EX1_TAKE_WHILE
