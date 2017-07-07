#include "Circle.h"

using namespace std;

Circle::Circle(double radius)
	:Shape("Circle", 1),
	radius(radius)
{
}

double Circle::calcArea()
{
	return M_PI * radius * radius;
}

double Circle::calcPerimeter()
{
	return M_PI * radius * 2;
}

Circle::~Circle()
{
}
