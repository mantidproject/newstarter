#pragma once
#include <string>
#include <iostream>
#include <math.h>

using namespace std;

class Shape
{
public:
	Shape();
	Shape(string type, int sideCount);
	virtual string getType();
	~Shape();
	virtual double calcArea() const;
	virtual double calcPerimeter() const;
	virtual void print();
	int sideCount;
	string shapeType;
	
};

