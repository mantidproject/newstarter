#include "Circle.h"
#include <math.h>

namespace Shapes
{
	Circle::Circle(double radius)
	{
		this->radius = radius;
		type = ShapeType::CIRCLE;
		this->numSides = 0;
	}

	Circle::~Circle()
	{
	}

	double Circle::calculateArea()
	{
		return PI * radius * radius;
	}

	double Circle::calculatePerimeter()
	{
		return 2 * PI * radius;
	}
};