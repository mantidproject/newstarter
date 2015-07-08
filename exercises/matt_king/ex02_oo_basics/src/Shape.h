/**
*  Contains methods whose bodies are contained in Shape.cpp
*/

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
	Shape();
	Shape(const std::string& type, int sides);
	virtual ~Shape();
	virtual std::string getType();
	virtual double getArea();
	virtual double getPerimeter();
	virtual int getNoOfSides();
	virtual double calculateArea();
	virtual double calculatePerimeter();
	virtual void print();

	double area;
	double perimeter;

private:
	std::string shapeType;
	int noOfSides;
};

#endif //Shape.h