
#include "Triangle.h"
#include "shapeEnum.h"

#include <string>
#include <math.h>

struct Triangle::TriangleImpl {
	TriangleImpl() {}

	static const int sides = 3;
	static const std::string shapeName;
};

const std::string Triangle::TriangleImpl::shapeName = "Triangle";

Triangle::Triangle(double base, double height, shapes shapeEnum) 
	: Shape(triangleData->shapeName, triangleData->sides, shapeEnum, base, height),
	triangleData(new TriangleImpl()) {}

Triangle::~Triangle() {
	delete triangleData;
	triangleData = nullptr;
}

double Triangle::getArea() const{
	return 0.5 * (getShapeWidth() * getShapeHeight());
}

double Triangle::getPerimeter() const {
	//Perimeter = base + 2sqrt(h^2 + (base^2/4))
	double baseSqauredOverFour = pow(getShapeWidth(), 2) / 4;
	double squareRootSummation = sqrt(pow(getShapeHeight(), 2) + baseSqauredOverFour);
	return getShapeWidth() + 2 * squareRootSummation;
}