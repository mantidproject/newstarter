/*****************************INCLUDES**********************************/
#include "Shape.h"
#include <string>
#include <iomanip>
#include <iostream>


/****************************CONSTRUCTORS*******************************/
Shape::Shape(){}

Shape::~Shape(){}

/****************************MEMBER FUNCTIONS****************************/

void Shape::print(){
	std::cout << "============================================" << std::endl;
	std::cout << std::setw(12) << std::left << "Type: " << std::setw(10) << std::left << getType() << std::endl;
	std::cout << std::setw(12) << std::left << "Area: " << std::setw(10) << std::left << getArea() << std::endl;
	std::cout << std::setw(12) << std::left <<"Perimeter: " << std::setw(10) << std::left << getPerimeter() << std::endl;
}

/******************************ACCESSORS*********************************/

std::string Shape::getType()		{	return type;		}
int Shape::getSides()				{	return sides;		}
double Shape::getArea()				{	return area;		}
double Shape::getPerimeter()		{	return perimeter;	}
double Shape::getWidth()			{   return width;		}
double Shape::getHeight()			{	return height;		}

/*******************************MUTATORS*********************************/

void Shape::setType(const std::string &t)	{   type = t;		}
void Shape::setSides(const int &s)			{   sides = s;		}
void Shape::setArea(const double &a)		{	area = a;		}
void Shape::setPerimeter(const double &p)	{	perimeter = p;	}
void Shape::setHeight(const double &h)		{	height = h;		}
void Shape::setWidth(const double &w)		{   width = w;		}

/****************************END OF FILE*********************************/
