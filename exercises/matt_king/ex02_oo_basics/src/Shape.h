#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>

class Shape
{
public:
	Shape();
	Shape(const std::string& type);
	virtual ~Shape();
	virtual std::string getType();
	virtual double calculateArea();
	virtual double calculatePerimeter();
	virtual void print();
	//NOT SURE IF THESE ARE NEEDED

	//virtual double getArea();
	//virtual double getPerimeter();

	double area;
	double perimeter;
	int noOfSides;

private:
	std::string shapeType;
};

#endif //Shape.h