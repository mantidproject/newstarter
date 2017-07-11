#ifndef EX1_WORD_CHAR_PREDICATES
#define EX1_WORD_CHAR_PREDICATES
/** Predicate for a character which may form part of a word.
 *  Any non whitespace character may form part of a word.
 *  @param Candidate The character to check.
 *  @return True for characters which may form part of a word, otherwise false.
 */
bool isWordChar(char Candidate);

/** Predicate for a character which denotes blank space or line breaks.
 *  Any non word character is a whitespace character.
 *  @param Candidate The character to check.
 *  @return Ture for characters which denote black space or line breaks.
 */
bool isWhitespaceChar(char Candidate);

#endif // EX1_WORD_CHAR_PREDICATES
