#include "ToLowerCase.h"
#include <algorithm>
#include <cctype>

void toLowerCase(std::string &MixedOrUpperCase) {
  std::transform(MixedOrUpperCase.cbegin(), MixedOrUpperCase.cend(),
                 MixedOrUpperCase.begin(),
                 [](unsigned char C) -> char { return std::tolower(C); });
}
