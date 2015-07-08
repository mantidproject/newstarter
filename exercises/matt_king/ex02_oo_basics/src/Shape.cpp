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
	return 0;
}
double Shape::calculatePerimeter()
{
	return 0;
}

double Shape::getArea()
{
	return calculateArea();
}

double Shape::getPerimeter()
{
	return calculatePerimeter();
}

int Shape::getNoOfSides()
{
	return noOfSides;
}

