#include <sstream>
#include <utility>

template <typename ConstCharInputIterator, typename CharPredicate>
std::pair<std::string, ConstCharInputIterator>
takeWhile(ConstCharInputIterator Begin, ConstCharInputIterator End,
          CharPredicate ShouldTake) {
  auto WordStream = std::stringstream();
  auto Current = Begin;
  while(Current != End && ShouldTake(*Current)) {
    WordStream << *Current;
    Current++;
  }
  return std::make_pair(WordStream.str(), Current);
}
