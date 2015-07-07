#include "Shape.h"

Shape::Shape(){
	Shape undefinedShape("Undefined");
}

Shape::Shape(std::string type)
{
	Shape::shapeType = type;
}

double Shape::calculateArea()
{
	//default area calculation 
	return 0;
}

double Shape::calculatePerimeter()
{
   //default perimeter calculation
	return 0;
}

std::string Shape::getType(){
	return shapeType;
}

