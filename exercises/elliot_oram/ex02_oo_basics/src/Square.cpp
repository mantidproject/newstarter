/********************************INCLUDES***********************************/
#include "Square.h"
#include <string>
#include <iostream>


/********************************CONSTRUCTORS*******************************/
Square::Square(){}

Square::Square(double h, double w):Shape(){
	setType("Square");
	setSides(4);
	setHeight(h);
	setWidth(w);
	setPerimeter(h*4);
	setArea(h*h);
}

Square::~Square(){}

/*******************************MEMBER FUNCTIONS****************************/
void Square::print(){
	std::cout << "=========================" << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
	std::cout << "Height: " << getHeight() << std::endl;
	std::cout << "Width: " << getWidth() << std::endl;
	std::cout << "=========================" <<std::endl;
}

/*********************************END OF FILE*******************************/