#pragma once
#include "Shape.h"
#include <math.h>

class Triangle : public Shape
{
public:
	Triangle(double base, double height);
	~Triangle();

	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print() const;

private:
	double base;
	double height;
	
};

