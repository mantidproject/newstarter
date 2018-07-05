#ifndef HEADER_RECTANGLE
#define HEADER_RECTANGLE

#include "Shape.h"

/*
Rectangle class
*/
class Rectangle : public Shape {

public:
	Rectangle(double h, double w);
	double area();
	double perimeter();

private:
	double height, width;
};


#endif