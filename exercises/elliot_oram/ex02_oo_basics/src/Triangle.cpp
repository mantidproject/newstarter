/********************************INCLUDES***********************************/
#include "Triangle.h"
#include <string>
#include <iostream>
#include <math.h>


/********************************CONSTRUCTORS*******************************/
Triangle::Triangle(){}

Triangle::Triangle(double h, double w):Shape(){
	setType("Triangle");
	setSides(3);
	setHeight(h);
	setWidth(w);
	setPerimeter(h + w + sqrt((h*h) + (w*w))); //Assumed to be right angled triangle
	setArea(0.5 * (h*w));
}

Triangle::~Triangle(){}

/*******************************MEMBER FUNCTIONS****************************/
void Triangle::print(){
	std::cout << "=========================" << std::endl;
	std::cout << "Type: " << getType() << std::endl;
	std::cout << "Area: " << getArea() << std::endl;
	std::cout << "Perimeter: " << getPerimeter() << std::endl;
	std::cout << "Height: " << getHeight() << std::endl;
	std::cout << "Width: " << getWidth() << std::endl;
	std::cout << "=========================" <<std::endl;
}

/*********************************END OF FILE*******************************/