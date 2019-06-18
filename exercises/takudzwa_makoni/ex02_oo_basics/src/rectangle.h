#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <string>
#include "shape.h"


class Rectangle : public Shape {

public:

	Rectangle(double width, double height);

	virtual unsigned int numOfSides() const override;
	virtual double area() const override;
	virtual double perimeter() const override;
	virtual std::string shapeType() const override;

private:

	
	const unsigned int m_numOfSides = 4;
	double m_sideHeight, m_sideWidth;

};



#endif