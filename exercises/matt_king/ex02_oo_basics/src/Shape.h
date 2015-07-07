#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

class Shape
{
public:
	Shape();
	Shape(std::string type);
	//~Shape();
	virtual std::string getType();
	virtual double calculateArea();
	virtual double calculatePerimeter();

private:
	std::string shapeType;
};

#endif //Shape.h