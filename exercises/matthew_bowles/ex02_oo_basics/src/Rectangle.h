#pragma once
#include "Shape.h"

class Rectangle :
	public Shape
{
public:
	Rectangle(double side1, double side2);
	~Rectangle();

	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print() const;

private:
	double side1;
	double side2;
};

