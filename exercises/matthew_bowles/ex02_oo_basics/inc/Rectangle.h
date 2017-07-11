#pragma once
#include "Shape.h"

class Rectangle :
	public Shape
{
public:
	Rectangle(double side1, double side2);
	~Rectangle();

	virtual double calcArea() const override;
	virtual double calcPerimeter() const override;
	virtual void print() const override;

private:
	double side1;
	double side2;
};

