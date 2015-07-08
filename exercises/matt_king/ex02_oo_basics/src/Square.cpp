/**
* Contains method definitions that are stated in Square.h
*/

#include "Square.h"
#include <cmath>

Square::Square(double side) : Shape("Square", 4)
{
	Square::side = side;
	area = calculateArea();
	perimeter = calculatePerimeter();
}
double Square::getSide()
{
	return side;
}
double Square::calculateArea()
{
	return pow(getSide(),2);
}
double Square::calculatePerimeter()
{
	return 4*getSide();
}