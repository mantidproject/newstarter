#include "Triangle.h"
#include <cmath>
#include <iostream>
#include <string>

Triangle::Triangle(double b, double h) : base(b), height(h) {
  std::cout << "Triangle Created" << std::endl;
}

double Triangle::area() { return 0.5 * base * height; }

double Triangle::perimeter() {
  return base + 2 * std::sqrt(height * height + base * base / 4);
}
