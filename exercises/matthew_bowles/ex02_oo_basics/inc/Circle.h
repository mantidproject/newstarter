#ifndef CIRCLE_H
#define CIRCLE_H

#include "Shape.h"

class Circle :
	public Shape
{
public:
	Circle(double radius);;

	double calcArea() const override;
	double calcPerimeter() const override;
	void print() const override;
	
private:
	double m_radius;
};

#endif
