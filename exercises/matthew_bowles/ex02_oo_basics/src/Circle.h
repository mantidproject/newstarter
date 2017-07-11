#pragma once
#include "Shape.h"
#include <math.h>

class Circle :
	public Shape
{
public:
	Circle(double radius);
	~Circle();

	double calcArea() const override;
	double calcPerimeter() const override;
	void print() const override;
	
private:
	double radius;
};

