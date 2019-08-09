/**
 * Skeleton main routine
 */

#include <boost/filesystem.hpp>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  if(argc <= 1) {
    std::cout << "Missing file name" << std::endl;
    return -1;
  }
  std::vector<std::string> arguments(argv+1, argc+argv);
  for (boost::filesystem::path arg : arguments) {
    if (!boost::filesystem::exists(arg)) {
      std::cout << arg << " does not exist" << std::endl;
      break;
    }
  }
  return 0;
}
