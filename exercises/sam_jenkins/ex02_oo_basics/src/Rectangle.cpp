#include "Shapes.h"
#include "Rectangle.h"
	Rectangle::Rectangle() :side1(1),side2(2)
	{
		type = "Rectangle";
		sides = 4;

	}
	Rectangle::Rectangle(double side1,double side2) :side1(side1),side2(side2)
	{
		type = "Rectangle";
		sides = 4;

	}
	double Rectangle::calcPerimiter() const{
		return (2 * side1) + (2* side2);
	}
	double Rectangle::calcArea() const {
		return side1*side2;
	}
