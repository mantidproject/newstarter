#include "Square.h"
#include <iostream>

Square::Square(double x) : length(x) {}

double Square::area() const { return length * length; }

double Square::perimeter() const { return 4 * length; }

std::string Square::getType() const { return type; }

int Square::getNoOfSides() const { return sides; }
