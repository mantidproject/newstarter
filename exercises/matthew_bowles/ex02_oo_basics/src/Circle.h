#pragma once
#include "Shape.h"

using namespace std;

class Circle :
	public Shape
{
public:
	Circle(double radius);
	virtual double calcArea();
	virtual double calcPerimeter();
	double radius;
	~Circle();
};

