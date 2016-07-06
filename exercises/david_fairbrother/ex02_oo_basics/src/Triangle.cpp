
#include "Triangle.h"

#include <string>

struct Triangle::TriangleImpl {
	TriangleImpl(double inBase, double inHeight) : base(inBase), height(inHeight) {}
	double base;
	double height;

	static const int sides = 3;
	static const std::string shapeName;
};

const std::string Triangle::TriangleImpl::shapeName = "Triangle";

Triangle::Triangle(double base, double height) : Shape(triangleData->shapeName, triangleData->sides),
	triangleData(new TriangleImpl(base, height)) {}

Triangle::~Triangle() {
	delete triangleData;
	triangleData = nullptr;
}

double Triangle::getArea() const{
	//TODO
	return 0;
}

double Triangle::getPerimeter() const {
	//TODO
	return 0;
}