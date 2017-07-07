#include "Circle.h"

Circle::Circle(double radius) 
	: Shape("Circle") {
	this->radius = radius;
}

Circle::~Circle() {
}

double Circle::perimeter() const {
	return this->radius * 2 * M_PI;
}

double Circle::area() const {
	return this->radius * this->radius * M_PI;
}