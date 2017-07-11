#pragma once
#include "Shape.h"
#include <math.h>

class Circle :
	public Shape
{
public:
	Circle(double radius);
	~Circle();

	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print() const;
	
private:
	double radius;
};

