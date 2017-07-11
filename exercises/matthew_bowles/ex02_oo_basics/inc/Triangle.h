#pragma once
#include "Shape.h"
#include <math.h>

class Triangle : public Shape
{
public:
	Triangle(double base, double height);
	~Triangle();

	virtual double calcArea() const override;
	virtual double calcPerimeter() const override;
	virtual void print() const override;

private:
	double base;
	double height;
	
};

