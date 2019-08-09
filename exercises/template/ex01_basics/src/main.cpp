/**
 * Skeleton main routine
 */

#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
  if(argc <= 1) {
    std::cout << "Missing file name" << std::endl;
    return -1;
  }
  std::vector<std::string> arguments(argv+1, argc+argv);
  for (auto arg : arguments) {
    std::cout << arg << std::endl;
  }
  return 0;
}
