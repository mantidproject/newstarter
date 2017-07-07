#pragma once
#include "Shape.h"

using namespace std;

class Rectangle :
	public Shape
{
public:
	Rectangle(double side1, double side2);
	virtual double calcArea();
	virtual double calcPerimeter();
	double side1;
	double side2;
	~Rectangle();
};

