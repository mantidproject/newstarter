#include "Rectangle.h"

Rectangle::Rectangle(double thisSide, double anotherSide) : Shape("Rectangle")
{
	Rectangle::oneSide = thisSide;
	Rectangle::theOtherSide = anotherSide;
	area = calculateArea();
	perimeter = calculatePerimeter();
}

double Rectangle::calculateArea()
{
	return oneSide*theOtherSide;
}

double Rectangle::calculatePerimeter()
{
	return 2*oneSide + 2*theOtherSide;
}

double Rectangle::getOneSide()
{
	return oneSide;
}
double Rectangle::getTheOtherSide(){
	return theOtherSide;
}