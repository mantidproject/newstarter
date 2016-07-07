
#include "Rectangle.h"

#include <string>

struct Rectangle::RectImpl {
	RectImpl() {}

	static const int sides = 4;
	static const std::string shapeName;
};

const std::string Rectangle::RectImpl::shapeName = "Rectangle";

Rectangle::Rectangle(double height, double width, shapes shapeEnum) 
	: Shape(rectData->shapeName, rectData->sides, shapeEnum, width, height),
	rectData(new RectImpl()) {}

Rectangle::~Rectangle() {
	delete rectData;
	rectData = nullptr;
}

double Rectangle::getArea() const {
	return getShapeHeight() * getShapeWidth();
}

double Rectangle::getPerimeter() const {
	return (getShapeHeight() * 2) + (getShapeWidth() * 2);
}