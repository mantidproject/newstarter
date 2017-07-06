template <typename ConstCharInputIterator, typename CharPredicate>
ConstCharInputIterator discardWhile(ConstCharInputIterator Begin,
                                    ConstCharInputIterator End,
                                    CharPredicate ShouldDiscard) {
  auto Current = Begin;
  while(Current != End && ShouldDiscard(*Current)) {
    Current++;
  }
  return Current;
}
