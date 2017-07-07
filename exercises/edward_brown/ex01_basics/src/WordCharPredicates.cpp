#include <cctype>

bool isWordChar(char Candidate) { return !static_cast<bool>(std::isspace(Candidate)); }

bool isWhitespaceChar(char Candidate) { return static_cast<bool>(std::isspace(Candidate)); }
