#pragma once
#include "Shape.h"

class Square :
	public Shape
{
public:
	Square(double side);
	~Square();

	virtual double calcArea() const override;
	virtual double calcPerimeter() const override;
	virtual void print() const override;
private:
	double side;

};

