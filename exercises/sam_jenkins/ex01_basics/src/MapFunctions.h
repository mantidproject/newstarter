#include <unordered_map>
#include <sstream>
#include <vector>
#include "StringManip.h"

///Put words into a map of the word and its frequency
std::unordered_map<std::string, int> countof(const std::string& input);

///Convert a map of strings and ints to a Vector of pairs of strings and ints
std::vector<std::pair<std::string, int>> mapToVector(std::unordered_map<std::string, int>map);
