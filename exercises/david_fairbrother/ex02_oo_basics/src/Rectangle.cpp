
#include "Rectangle.h"

#include <string>

struct Rectangle::RectImpl {
	RectImpl(double inHeight, double inWidth) : height(inHeight), width(inWidth) {}

	double height;
	double width;

	static const int sides = 4;
	static const std::string shapeName;
};

const std::string Rectangle::RectImpl::shapeName = "Rectangle";

Rectangle::Rectangle(double height, double width) : Shape(rectData->shapeName, rectData->sides),
	rectData(new RectImpl(height, width)) {}

Rectangle::~Rectangle() {
	delete rectData;
	rectData = nullptr;
}

double Rectangle::getArea() const {
	return rectData->height * rectData->width;
}

double Rectangle::getPerimeter() const {
	return (rectData->height * 2) + (rectData->width * 2);
}