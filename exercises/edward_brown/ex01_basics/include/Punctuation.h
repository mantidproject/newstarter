#include <string>

/** Determines if Candidate holds any of the following character values
 *  `.,?'"!():`.
 *
 *  @param The character to test.
 *  @return True if the Candidate is a punctuation mark, false if it is not.
 */
bool isPunctuation(char Candidate);

/** Creates a copy of the supplied string with the punctuation characters
 * removed. 
 *
 *  @param MaybeContainsPunctuation A string which may contain punctuation.
 *  @return A MaybeContainsPunctuation with the punctuation characters stripped.
 */
std::string stripPunctuation(std::string MaybeContainsPunctuation);
