#pragma once
#include "Shape.h"

class Square :
	public Shape
{
public:
	Square(double side);
	~Square();

	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print() const;
private:
	double side;

};

