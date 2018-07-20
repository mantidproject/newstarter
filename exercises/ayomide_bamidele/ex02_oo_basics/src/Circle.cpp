#include "Circle.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <cmath>

Circle::Circle(double r) : radius(r) {}

double Circle::area() const { return M_PI * radius * radius; }

double Circle::perimeter() const { return 2 * M_PI * radius; }

std::string Circle::getType() const { return type; }

int Circle::getNoOfSides() const { return sides; }
