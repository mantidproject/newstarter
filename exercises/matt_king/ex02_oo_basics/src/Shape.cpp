#include "Shape.h"

Shape::Shape(){
	Shape undefinedShape("Undefined");
}

Shape::Shape(const std::string& type)
{
	shapeType = type;
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

// NOT SURE IF I NEED THESE.

/* 
double Shape::getArea()
{
	return area;
}

double Shape::getPerimeter()
{
	return perimeter;
}
*/
