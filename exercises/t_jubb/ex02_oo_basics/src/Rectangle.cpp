#include <cmath>
#include <string>
#include <vector>

#include "Rectangle.h"
#include "Shape.h"


/*
Rectangle class
*/
Rectangle::Rectangle(double h, double w) {
		height = h;
		width = w;
		type = "Rectangle";
		sides = 4;
	};
double Rectangle::area() { return height * width; };
double Rectangle::perimeter() { return  2 * height + 2 * width; };
