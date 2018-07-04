#include <unordered_map>
#include <sstream>
#include "stringManip.h"
#include <vector>

std::unordered_map<std::string, int> countof(const std::string& input);
std::vector<std::pair<std::string, int>> mapToVector(std::unordered_map<std::string, int>map);
