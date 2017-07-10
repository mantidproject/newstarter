#pragma once
#include "Shape.h"

using namespace std;

class Rectangle :
	public Shape
{
public:
	Rectangle(double side1, double side2);
	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print();
	double side1;
	double side2;
	~Rectangle();
};

