#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"
#include <cmath>

class Triangle : public Shape
{
public:
	Triangle(double base, double height);

	double calcArea() const override;
	double calcPerimeter() const override;
	void print() const override;

private:
	double m_base;
	double m_height;
	
};

#endif
