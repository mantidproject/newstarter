#include "Shape.h"

Shape::Shape(){
	Shape undefinedShape("Undefined");
}

Shape::Shape(std::string type)
{
	shapeType = type;
}

Shape::~Shape(){
}

std::string Shape::getType(){
	return shapeType;
}

double Shape::calculateArea()
{
	return 0;
}
double Shape::calculatePerimeter()
{
	return 0;
}

double Shape::getArea()
{
	return area;
}

double Shape::getPerimeter()
{
	return perimeter;
}

