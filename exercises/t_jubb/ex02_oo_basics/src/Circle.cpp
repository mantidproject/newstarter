#include <cmath>
#include <string>

#include "Circle.h"
#include "Shape.h"

/*
Circle Class
*/
Circle::Circle(double r) {
		radius = r;
		type = "Circle";
		sides = 1;
	};

double Circle::area() { return M_PI * pow(radius, 2); };

double Circle::perimeter() { return  M_PI * 2 * radius; };