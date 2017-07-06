#include <cctype>

bool isWordChar(char Candidate) {
  return !std::isspace(Candidate);
}

bool isWhitespaceChar(char Candidate) {
  return std::isspace(Candidate);
}
