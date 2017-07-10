#include "Punctuation.h"
#include <algorithm>

/** Determines if Candidate holds any of the following character values
 *  `.,?'"!():`.
 *
 *  @param The character to test.
 *  @return True if the Candidate is a punctuation mark, false if it is not.
 */
bool isPunctuation(char Candidate) {
  static auto const punctuation = std::string(".,?'\\\"!():");
  return std::find(punctuation.cbegin(), punctuation.cend(), Candidate) !=
         punctuation.cend();
}

/** Performs in place modification of the string MaybeContainsPunctuation
 * such that it no longer constains puncutation characters.
 *  @param MaybeContainsPunctuation A string to be modified which may contain
 * punctuation.
 */
void stripPunctuation(std::string &MaybeContainsPunctuation) {
  MaybeContainsPunctuation.erase(
      std::remove_if(MaybeContainsPunctuation.begin(),
                     MaybeContainsPunctuation.end(), &isPunctuation),
      MaybeContainsPunctuation.end());
}
