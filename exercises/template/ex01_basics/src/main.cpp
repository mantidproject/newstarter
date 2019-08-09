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

std::string load_file(std::string f) {
  std::ifstream infile(f);
  std::stringstream buffer;
  buffer << infile.rdbuf();
  return buffer.str();
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

  std::vector<std::string> contents;
  contents.resize(arguments.size());
  std::transform(arguments.begin(), arguments.end(), contents.begin(), load_file);
  std::string combined = "";
  combined = std::accumulate(contents.begin(), contents.end(), combined);

  std::cout << combined << std::endl;

  return 0;
}
