
#include "Circle.h"

#include <string>
#include <math.h>

struct Circle::CircleImpl {
	CircleImpl(double inRadius) : radius(inRadius) {}
	double radius;

	static const int sides = 1;
	static const std::string shapeName;
};

const std::string Circle::CircleImpl::shapeName = "Circle";

Circle::Circle(double radius) : Shape(circleData->shapeName, circleData->sides),
	circleData(new CircleImpl(radius)) {}


Circle::~Circle() {
	delete circleData;
	circleData = nullptr;
}

double Circle::getArea() const {
	return pow(circleData->radius, 2)  * M_PI;
}

double Circle::getPerimeter() const {
	return (circleData->radius * 2) * M_PI;
}