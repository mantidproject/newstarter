#pragma once
#include "Shape.h"

using namespace std;

class Square :
	public Shape
{
public:
	Square(double side1);
	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print();
	double side1;
	~Square();
};

