#include "Punctuation.h"
#include <algorithm>

bool isPunctuation(char Candidate) {
  auto const punctuation = std::string(".,?'\\\"!():");
  return std::find(punctuation.cbegin(), punctuation.cend(), Candidate) !=
         punctuation.cend();
}

std::string stripPunctuation(std::string MaybeContainsPunctuation) {
  MaybeContainsPunctuation.erase(
      std::remove_if(MaybeContainsPunctuation.begin(),
                     MaybeContainsPunctuation.end(), &isPunctuation),
      MaybeContainsPunctuation.end());
  return MaybeContainsPunctuation;
}
