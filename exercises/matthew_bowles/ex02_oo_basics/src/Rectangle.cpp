#include "Rectangle.h"

using namespace std;

Rectangle::Rectangle(double side1, double side2)
	:Shape("Rectangle", 4),
	side1(side1)
{
}

double Rectangle::calcArea()
{
	return side1*side2;
}

double Rectangle::calcPerimeter()
{
	return side1 * 2 + side2 * 2;
}

Rectangle::~Rectangle()
{
}
