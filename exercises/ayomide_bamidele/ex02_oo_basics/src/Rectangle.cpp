#include "Rectangle.h"
#include <iostream>

Rectangle::Rectangle(double x, double y) : breadth(x), length(y) {}

double Rectangle::area() const { return length * breadth; }

double Rectangle::perimeter() const { return 2 * (length + breadth); }

std::string Rectangle::getType() const { return type; }

int Rectangle::getNoOfSides() const { return sides; }
