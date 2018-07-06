#include "Shapes.h"
#include "Circle.h"
#include <math.h>

	Circle::Circle() :radius(1)
	{
		type = "Circle";
		sides = 1;
	}
	Circle::Circle(double radius) :radius(radius)
	{
		type = "Circle";
		sides = 1;
	}
	double Circle::calcPerimiter()const {
		return 2 * radius*M_PI;
	}
	double Circle::calcArea() const {
		return  radius*radius*M_PI;
	}


