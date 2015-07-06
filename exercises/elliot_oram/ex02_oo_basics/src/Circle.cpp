/********************************INCLUDES***********************************/
#include "Circle.h"

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <string>

/********************************CONSTRUCTORS*******************************/
Circle::Circle(){}

Circle::Circle(double h, double w):Shape(){
	setType("Circle");
	setSides(1);
	setHeight(h);
	setPerimeter(2*M_PI*h);
	setArea(M_PI*(h*h));
}

Circle::~Circle(){}

/*******************************MEMBER FUNCTIONS****************************/
void Circle::print(){
	std::cout << "=========================" << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
	std::cout << "Radius: " << getHeight() << std::endl;
	std::cout << "=========================" <<std::endl;
}

/*********************************END OF FILE*******************************/