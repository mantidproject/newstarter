/**
 * Skeleton main routine
 */

#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <numeric>
#include <sstream>
#include <vector>

bool fileMissing(std::string f) {
  return !boost::filesystem::exists(f);
}

std::string load_file(std::string acc, std::string f) {
  std::ifstream infile(f);
  std::stringstream buffer;
  buffer << infile.rdbuf();
  return acc + buffer.str();
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

  std::string combined = "";
  combined = std::accumulate(arguments.begin(), arguments.end(), combined, load_file);

  std::cout << combined << std::endl;

  return 0;
}
