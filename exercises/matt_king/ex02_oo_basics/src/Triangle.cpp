/**
* Contains method definitions that are stated in Triangle.h
*/

#include "Triangle.h"
#include <cmath>

Triangle::Triangle(double width, double height) : Shape("Triangle", 3)
{ 
	base = width;
	Triangle::height = height;
	area = calculateArea();
	perimeter = calculatePerimeter();
};

double Triangle::calculateArea()
{
	return 0.5 * base * height;
}

double Triangle::calculatePerimeter()
{
	return double(sqrt(2*pow(base,2) + 4*pow(height,2)));
}

double Triangle::getBase(){
	return base;
}
double Triangle::getHeight(){
	return height;
}