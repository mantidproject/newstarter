#pragma once
#include <string>
#include <math.h>

using namespace std;

class Shape
{
public:
	Shape();
	Shape(string type, int sideCount);
	~Shape();
	virtual double calcArea();
	virtual double calcPerimeter();
	int sideCount;
	string shapeType;
};

