/**
 * Skeleton main routine
 */

#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>

bool fileMissing(std::string f) {
  return !boost::filesystem::exists(f);
}

int main(int argc, char **argv)
{
  if(argc <= 1) {
    std::cout << "Missing file name" << std::endl;
    return -1;
  }

  std::vector<std::string> arguments(argv+1, argc+argv);

  auto missing = std::find_if(arguments.begin(), arguments.end(), fileMissing);

  if (missing != arguments.end()) {
    std::cout << "Cannot find file " << *missing << std::endl;
    return -1;
  }

  for (std::string arg : arguments) {
    std::cout << arg << std::endl;
  }
  return 0;
}
