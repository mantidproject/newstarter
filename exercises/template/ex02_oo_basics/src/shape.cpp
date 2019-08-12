#include "shape.hpp"

#include <iostream>

ostream &operator<<(ostream &os, const Shape *shape) {
  // Print the important parts of a shape
  os << "A " << shape->type();
  os << " with " << shape->sides() << " sides";
  os << ", a permieter of " << shape->perimeter();
  os << ", and and area of " << shape->area();
  return os;
};

int Circle::sides() const { return 1; }
double Circle::perimeter() const { return 2 * M_PI * radius; }
double Circle::area() const { return M_PI * radius * radius; }
string Circle::type() const { return "circle"; }

int Square::sides() const { return 4; }
double Square::perimeter() const { return 4 * side; }
double Square::area() const { return side * side; }
string Square::type() const { return "square"; }

int Rectangle::sides() const { return 4; }
double Rectangle::perimeter() const { return 2 * (width + height); }
double Rectangle::area() const { return width * height; }
string Rectangle::type() const { return "rectangle"; }

int Triangle::sides() const { return 3; }
double Triangle::perimeter() const {
  return base + 2 * sqrt(height * height + base * base / 4);
}
double Triangle::area() const { return 0.5 * base * height; }
string Triangle::type() const { return "triangle"; }
