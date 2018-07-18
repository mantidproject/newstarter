#ifndef GUARD_stringManip_h
#define GUARD_stringManip_h
#include <string>
#include <cctype>
#include <regex>

///Function to find spaces and hyphens
bool space(const char& c);

///Function to remove all delimiters from string
void stripString(std::string& input);

#endif
