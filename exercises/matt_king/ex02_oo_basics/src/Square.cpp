#include "Square.h"

Square::Square(double side) : Shape("Square")
{
	Square::side = side;
	area = calculateArea();
	perimeter = calculatePerimeter();
	noOfSides = 4;
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