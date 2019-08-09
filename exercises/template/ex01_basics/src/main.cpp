/**
 * Skeleton main routine
 */

#include <iostream>

int main(int argc, char **argv)
{
  if(argc <= 1) {
    std::cout << "Missing file name" << std::endl;
    return -1;
  }
  std::cout << "Found file" << std::endl;
  std::cout << argv[1] << std::endl;
  return 0;
}
