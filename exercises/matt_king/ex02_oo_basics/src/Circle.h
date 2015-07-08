/**
*  Contains methods whose bodies are contained in Circle.cpp
*/

#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle : public Shape
{
public:
	Circle();
	Circle(double radius);
	double getRadius();
	double calculateArea();
	double calculatePerimeter();
private:
	double radius;
};

#endif