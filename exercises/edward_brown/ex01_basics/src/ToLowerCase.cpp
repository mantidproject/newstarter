#include "ToLowerCase.h"
#include <algorithm>
#include <byte>

std::string toLowerCase(std::string MixedOrUpperCase) {
  std::transform(MixedOrUpperCase.cbegin(), MixedOrUpperCase.cend(),
                 MixedOrUpperCase.begin(),
                 [](char C) -> char { return std::tolower(C); });
  return MixedOrUpperCase;
}
