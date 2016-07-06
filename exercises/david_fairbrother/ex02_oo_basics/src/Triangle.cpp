
#include "Triangle.h"

#include <string>
#include <math.h>

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
	return 0.5 * (triangleData->base * triangleData->height);
}

double Triangle::getPerimeter() const {
	//Perimeter = base + 2sqrt(h^2 + (base^2/4))
	double baseSqauredOverFour = pow(triangleData->base, 2) / 4;
	double squareRootSummation = sqrt(pow(triangleData->height, 2) + baseSqauredOverFour);
	return triangleData->base + 2 * squareRootSummation;
}