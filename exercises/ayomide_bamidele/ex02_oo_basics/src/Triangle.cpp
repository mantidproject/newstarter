#include "Triangle.h"
#include <cmath>
#include <iostream>
#include <string>

Triangle::Triangle(double b, double h) : base(b), height(h) {}

double Triangle::area() const { return 0.5 * base * height; }

double Triangle::perimeter() const {
  return base + 2 * std::sqrt(height * height + base * base / 4);
}

std::string Triangle::getType() const { return type; }

int Triangle::getNoOfSides() const { return sides; }
