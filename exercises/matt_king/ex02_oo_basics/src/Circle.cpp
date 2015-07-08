/**
* Contains method definitions that are stated in Circle.h
*/

#include "Circle.h"

#include <cmath>



static const double PI = 3.1415926;

Circle::Circle(double radius) : Shape("Circle", 1){
	Circle::radius = radius;
	area = calculateArea();
	perimeter = calculatePerimeter();
};

double Circle::getRadius()
{
	return radius;
};

double Circle::calculateArea(){
	return pow(getRadius(),2)*PI;
};
double Circle::calculatePerimeter(){
	return 2*getRadius()*PI;
};

