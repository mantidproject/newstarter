#include <string>
#include <vector>

#include "Square.h"
#include "Shape.h"


/*
Square class
*/

Square::Square(double h) {
	height = h;
	type = "Square";
	sides = 4;
};

double Square::area() { return height * height; };
double Square::perimeter() { return 4 * height; };
