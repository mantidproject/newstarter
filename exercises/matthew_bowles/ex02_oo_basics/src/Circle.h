#pragma once
#include "Shape.h"

using namespace std;

class Circle :
	public Shape
{
public:
	Circle(double radius);
	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print();
	double radius;
	~Circle();
};

