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
 *  @return The a pair (A,B) where A is the substring s, and B is an iterator
 * pointing to to the character which immediately follows s or, End, if the
 * length of s matches the distance between Begin and End.
 */
template <typename ConstCharInputIterator, typename CharPredicate>
std::pair<std::string, ConstCharInputIterator>
takeWhile(ConstCharInputIterator Begin, ConstCharInputIterator End,
          CharPredicate ShouldTake) {
  auto TakeEnd = std::find_if_not(Begin, End, ShouldTake);
  auto Taken = std::string(Begin, TakeEnd);
  return std::make_pair(Taken, TakeEnd);
}
#endif // EX1_TAKE_WHILE
