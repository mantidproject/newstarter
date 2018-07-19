#include "Circle.h"
#include <iostream>

Circle::Circle(double r) : radius(r) {}

double Circle::area() const { return 3.14 * radius * radius; }

double Circle::perimeter() const { return 6.28 * radius; }

std::string Circle::getType() const { return type; }

int Circle::getNoOfSides() const { return sides; }
