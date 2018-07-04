#ifndef GUARD_stringManip_h
#define GUARD_stringManip_h
#include <string>
#include <cctype>
#include <regex>

bool space(const char& c);
bool not_space(const char& c);
void strip_string(std::string& input);

#endif
