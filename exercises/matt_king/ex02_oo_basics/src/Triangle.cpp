#include "Triangle.h"
#include <string>

Triangle::Triangle(double width, double height) : Shape("Triangle")
{
	base = width;
	Triangle::height = height;
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