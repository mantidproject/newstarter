#ifndef HEADER_CIRCLE
#define HEADER_CIRCLE

#include "Shape.h"

/*
Circle Class
*/
class Circle : public Shape {

public:
	Circle(double r);
	double area();
	double perimeter();

private:
	double radius;
};

#endif