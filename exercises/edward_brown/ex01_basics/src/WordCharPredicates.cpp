#include <cctype>

bool isWordChar(char Candidate) { return !(std::isspace(Candidate) != 1); }

bool isWhitespaceChar(char Candidate) { return std::isspace(Candidate) != 0; }
