#include "Circle.h"

#include <cmath>


const double pi = 3.1415926;

Circle::Circle(double radius) : Shape("Circle"){
	Circle::radius = radius;
	area = calculateArea();
	perimeter = calculatePerimeter();
	noOfSides = 1;
};

double Circle::getRadius()
{
	return radius;
};

double Circle::calculateArea(){
	return pow(getRadius(),2)*pi;
};
double Circle::calculatePerimeter(){
	return 2*getRadius()*pi;
};

