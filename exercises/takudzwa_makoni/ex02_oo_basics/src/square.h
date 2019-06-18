#ifndef SQUARE_H
#define SQUARE_H

#include <string>
#include "shape.h"

//class square : public shape;


class Square : public Shape {

public:
	
	Square(double length);

	virtual unsigned int numOfSides() const override; 
	virtual std::string shapeType() const override; 
	virtual double area() const override;
	virtual double perimeter() const override;

private:

	const unsigned int m_numOfSides = 4;
	double m_length;

};

#endif