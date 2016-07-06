
#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle : public Shape{
public:
	Rectangle(double height, double width);
	~Rectangle();

	double getArea() const;
	double getPerimeter() const;

private:
	struct RectImpl;
	RectImpl *rectData;
};

#endif