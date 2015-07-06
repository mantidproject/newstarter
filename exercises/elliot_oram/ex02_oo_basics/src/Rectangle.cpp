/********************************INCLUDES***********************************/
#include "Rectangle.h"
#include <string>
#include <iostream>



/********************************CONSTRUCTORS*******************************/
Rectangle::Rectangle(){}

Rectangle::Rectangle(double h, double w):Shape(){
	setType("Rectangle");
	setSides(4);
	setHeight(h);
	setWidth(w);
	setPerimeter((2*h) + (2*w));
	setArea(h*w);
}

Rectangle::~Rectangle(){}

/*******************************MEMBER FUNCTIONS****************************/
void Rectangle::print(){
	std::cout << "=========================" << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
	std::cout << "Height: " << getHeight() << std::endl;
	std::cout << "Width: " << getWidth() << std::endl;
	std::cout << "=========================" <<std::endl;
}

/*********************************END OF FILE*******************************/