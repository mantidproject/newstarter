#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double x, double y) : breadth(x), length(y) {
  std::cout << "Rectangle Created" << std::endl;
}

double Rectangle::area() { return length * breadth; }

double Rectangle::perimeter() { return 2 * (length + breadth); }
