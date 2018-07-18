#include "Shapes.h"
#include "Circle.h"
#include <math.h>

	Circle::Circle() :Shapes("Circle",1), radius(1)	{}

	Circle::Circle(double radius) : Shapes("Circle", 1), radius(radius)	{}

	double Circle::calcPerimiter() const {
		return 2 * radius*M_PI;
	}
	double Circle::calcArea() const {
		return  radius*radius*M_PI;
	}


