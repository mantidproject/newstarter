/**
*  Contains methods whose bodies are contained in Rectangle.cpp
*/

#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape
{
public:
	Rectangle();
	Rectangle(double oneSide, double anotherSide);
	~Rectangle(){};
	double calculateArea();
	double calculatePerimeter();
	double getOneSide();
	double getTheOtherSide();
private:
	double oneSide, theOtherSide;
};

#endif // !RECTANGLE_H
