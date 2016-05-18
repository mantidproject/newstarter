/**
 * Skeleton main routine
 */
#include <utility>
#include <cmath>
#include <iostream>

void foo(int&& bar){
  
}
 
int main(int, char **)
{
  // Do some c++11 type stuff
  auto x = 1;
  foo(std::move(x));
  
  // Use M_PI
  std::cout << M_PI << std::endl;

}