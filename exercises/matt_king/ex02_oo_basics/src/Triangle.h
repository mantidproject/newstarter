#ifndef TRIANGLE_H
#define TRIANGLE_H
#include "Shape.h"
#include <iostream>

class Triangle : public Shape
{
public:
	Triangle();
	Triangle(double base, double height);
	double getBase();
	double getHeight();
	double calculateArea();
	double calculatePerimeter();

private:
	double base;
	double height;
};


#endif
