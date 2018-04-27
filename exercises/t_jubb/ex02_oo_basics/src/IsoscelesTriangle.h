#ifndef HEADER_ISOSCELESTRIANGLE
#define HEADER_ISOSCELESTRIANGLE

#include "Shape.h"

/*
Triangle Class
*/
class IsoscelesTriangle : public Shape {

public:
	IsoscelesTriangle(double b, double h);
	double area();
	double perimeter();

private:
	double base, height;
};

#endif