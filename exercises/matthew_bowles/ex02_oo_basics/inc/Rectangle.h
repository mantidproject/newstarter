#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "Shape.h"

class Rectangle :
	public Shape
{
public:
	Rectangle(double side1, double side2);

	double calcArea() const override;
	double calcPerimeter() const override;
	void print() const override;

private:
	double m_side1;
	double m_side2;
};

#endif
