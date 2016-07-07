
#include "Circle.h"
#include "shapeEnum.h"

#include <string>
#include <math.h>

struct Circle::CircleImpl {
	CircleImpl() {}

	static const int sides = 1;
	static const std::string shapeName;
};

const std::string Circle::CircleImpl::shapeName = "Circle";

Circle::Circle(double radius, shapes shapeEnum) 
	: Shape(circleData->shapeName, circleData->sides, shapeEnum, radius),
	circleData(new CircleImpl()) {}


Circle::~Circle() {
	delete circleData;
	circleData = nullptr;
}

double Circle::getArea() const {
	return pow(getShapeWidth(), 2)  * M_PI;
}

double Circle::getPerimeter() const {
	return (getShapeWidth() * 2) * M_PI;
}