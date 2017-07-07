#include "ToLowerCase.h"
#include <algorithm>
#include <cctype>

std::string toLowerCase(std::string MixedOrUpperCase) {
  std::transform(MixedOrUpperCase.cbegin(), MixedOrUpperCase.cend(),
                 MixedOrUpperCase.begin(),
                 [](char C) -> char { return std::tolower(C); });
  return MixedOrUpperCase;
}
