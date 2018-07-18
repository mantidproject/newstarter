#include "Circle.h"
#include <iostream>
Circle::Circle(double r) : radius(r) {
  std::cout << "Circle Created" << std::endl;
}

double Circle::area() { return 3.14 * radius * radius; }

double Circle::perimeter() { return 6.28 * radius; }
