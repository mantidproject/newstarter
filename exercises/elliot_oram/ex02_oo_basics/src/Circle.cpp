//Includes
#include "Circle.h"

#define _USE_MATH_DEFINES
#include <iomanip>
#include <iostream>
#include <math.h>
#include <string>

//Constructors
Circle::Circle(){}

Circle::Circle(double h, double w):Shape(){
	setType("Circle");
	setSides(1);
	setHeight(h);
	setPerimeter(2*M_PI*h);
	setArea(M_PI*(h*h));
}

Circle::~Circle(){}

//Member Fuctions
void Circle::print(){
	Shape::print();
	std::cout << std::setw(12) << std::left << "Radius: " << std::setw(10) << std::left << getHeight() << std::endl;
	std::cout << "============================================" <<std::endl;
}

//End of File