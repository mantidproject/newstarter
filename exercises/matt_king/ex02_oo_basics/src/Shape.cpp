/**
* Contains method definitions that are stated in Shape.h
*/


#include "Shape.h"

Shape::Shape(){
	Shape undefinedShape("Undefined", 0);
}

Shape::Shape(const std::string& type, int sides)
{
	shapeType = type;
	noOfSides = sides;
}

Shape::~Shape(){
}

void Shape::print(){
	std::cout << "Type: " << shapeType.c_str() << std::endl;
	std::cout << "Sides: " << noOfSides << std::endl;
	std::cout << "Area: " << area << std::endl;
	std::cout << "Perimeter: " << perimeter << std::endl;
	std::cout << "\n";
}
std::string Shape::getType(){
	return shapeType;
}

double Shape::calculateArea()
{
	area = 0;
	return area;
}
double Shape::calculatePerimeter()
{
	perimeter = 0;
	return perimeter;
}

double Shape::getArea()
{
	return area;
}

double Shape::getPerimeter()
{
	return perimeter;
}

int Shape::getNoOfSides()
{
	return noOfSides;
}

