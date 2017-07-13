#ifndef SQUARE_H
#define SQUARE_H

#include "Shape.h"

class Square :
	public Shape
{
public:
	Square(double side);

	double calcArea() const override;
	double calcPerimeter() const override;
	void print() const override;
private:
	double m_side;

};

#endif
