#pragma once
#include "Shape.h"

using namespace std;

class Triangle : public Shape
{
public:
	Triangle(double base, double height);
	virtual double calcArea();
	virtual double calcPerimeter();
	virtual void print();
	virtual string getType();
	double base;
	double height;
	~Triangle();
};

