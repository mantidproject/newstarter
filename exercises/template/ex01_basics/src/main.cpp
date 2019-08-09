/**
 * Skeleton main routine
 */

#include <algorithm>
#include <boost/filesystem.hpp>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <vector>

bool fileMissing(std::string f) {
  return !boost::filesystem::exists(f);
}

std::map<std::string, int> load_file(std::map<std::string, int> acc, std::string f) {
  std::ifstream infile(f);
  std::stringstream buffer;
  buffer << infile.rdbuf();
  if (acc.count(buffer.str()) >= 1) {
    acc[buffer.str()] += 1;
  } else{
    acc[buffer.str()] = 1;
  }
  return acc;
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

  std::map<std::string, int> combined;
  combined = std::accumulate(arguments.begin(), arguments.end(), combined, load_file);

  for (auto i : combined) {
    std::cout << i.first << " ==> " << i.second << std::endl;
  }

  return 0;
}
