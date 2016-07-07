
#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"
#include "shapeEnum.h"

class Square : public Shape{
public:
	Square(double sideLength, shapes shapeEnum);
	~Square();

	double getArea() const;
	double getPerimeter() const;

private:
	struct SquareImpl;
	SquareImpl *squareData;
};

#endif