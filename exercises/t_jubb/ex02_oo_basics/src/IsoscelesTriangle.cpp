#include <cmath>
#include <string>
#include <vector>

#include "IsoscelesTriangle.h"
#include "Shape.h"

/*
Triangle Class
*/
IsoscelesTriangle::IsoscelesTriangle(double b, double h) {
		base = b;
		height = h;
		type = "Triangle";
		sides = 3;
	};
double IsoscelesTriangle::area() { return 0.5 * base * height; };
double IsoscelesTriangle::perimeter() { return  base + 2 * sqrt(pow(height, 2) + 0.25 * pow(base, 2)); };