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
	~Shape();
	std::string getType();
	int getNoOfSides();
	double getArea();
	double getPerimeter();
	virtual double calculateArea();
	virtual double calculatePerimeter();
	void print();

	double area;
	double perimeter;

private:
	std::string shapeType;
	int noOfSides;
};

#endif //Shape.h