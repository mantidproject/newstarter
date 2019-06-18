#ifndef CIRCLE_H
#define CIRCLE_H

#include <string>
#include "shape.h"

class Circle : public Shape { // circle class

public:
	Circle(double radius);

	virtual unsigned int numOfSides() const override;
	virtual double area() const override;
	virtual double perimeter() const  override;
	virtual std::string shapeType() const override;

private:

	const unsigned int m_numOfSides = 1;
	const double m_pi = 3.14159;
	double m_radius;
};

#endif