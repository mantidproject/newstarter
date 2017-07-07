#pragma once
#include "Shape.h"

using namespace std;

class Square :
	public Shape
{
public:
	Square(double side1);
	virtual double calcArea();
	virtual double calcPerimeter();
	double side1;
	~Square();
};

