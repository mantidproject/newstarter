#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape
{
public:
	Shape();
	Shape(std::string type);
	virtual ~Shape();
	virtual std::string getType();
	virtual double calculateArea();
	virtual double calculatePerimeter();
	virtual double getArea();
	virtual double getPerimeter();

	double area;
	double perimeter;

private:
	std::string shapeType;
};

#endif //Shape.h