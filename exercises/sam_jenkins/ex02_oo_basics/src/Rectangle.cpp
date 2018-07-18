#include "Shapes.h"
#include "Rectangle.h"
	Rectangle::Rectangle() :Shapes("Rectangle", 4), side1(1),side2(2)
	{


	}
	Rectangle::Rectangle(double side1,double side2) : Shapes("Rectangle", 4), side1(side1),side2(side2)
	{


	}
	double Rectangle::calcPerimiter() const{
		return (2 * side1) + (2* side2);
	}
	double Rectangle::calcArea() const {
		return side1*side2;
	}
