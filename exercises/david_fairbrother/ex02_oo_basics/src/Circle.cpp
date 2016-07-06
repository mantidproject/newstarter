
#include "Circle.h"

#include <string>

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
	//TODO
	return 0;
}

double Circle::getPerimeter() const {
	//TODO
	return 0;
}