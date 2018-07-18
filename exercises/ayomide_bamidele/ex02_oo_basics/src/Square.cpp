#include "Square.h"
#include <iostream>

Square::Square(double x) : length(x) {
  std::cout << "Square Created" << std::endl;
}

double Square::area() { return length * length; }

double Square::perimeter() { return 4 * length; }
