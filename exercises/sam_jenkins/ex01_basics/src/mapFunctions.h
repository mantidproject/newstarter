#include <unordered_map>
#include <sstream>
#include <vector>
#include "stringManip.h"


std::unordered_map<std::string, int> countof(const std::string& input);
std::vector<std::pair<std::string, int>> mapToVector(std::unordered_map<std::string, int>map);
bool compare(const std::pair<std::string, int>& left, const std::pair<std::string, int>& right);