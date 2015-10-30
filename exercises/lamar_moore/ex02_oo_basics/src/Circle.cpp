#include "Circle.h"
#include <math.h>

namespace Shapes
{
	Circle::Circle(double radius): m_radius(radius)
	{
	}

	Circle::~Circle()
	{
	}

	const double Circle::calculateArea()
	{
		return PI * m_radius * m_radius;
	}

	const double Circle::calculatePerimeter()
	{
		return 2 * PI * m_radius;
	}

	const ShapeType Circle::getType()
	{
		return CIRCLE;
	}

	const int Circle::getNumSides()
	{
		return 0;
	}
};