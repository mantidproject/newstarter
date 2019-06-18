#ifndef ISOTRIANGLE_H
#define ISOTRIANGLE_H

#include <string>
#include <math.h> //sqrt
#include "shape.h"



class IsoTriangle : public Shape { // isosceles triangle class

public:

	IsoTriangle(double base, double height);

	virtual unsigned int numOfSides() const override; 
	virtual std::string shapeType() const override; 

	virtual double area() const override; 
	virtual double perimeter() const override;

private:

	const unsigned int m_numOfSides = 3;
	double m_base, m_height;
	

};

#endif