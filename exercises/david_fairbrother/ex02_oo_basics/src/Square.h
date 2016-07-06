
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square : public Shape{
public:
	Square(double sideLength);
	~Square();

	double getArea() const;
	double getPerimeter() const;

private:
	struct SquareImpl;
	SquareImpl *squareData;
};

#endif