
#include "Shape.h"
#include "shapeEnum.h"

#include <string>

using namespace std;

struct Shape::ShapeImpl {
	ShapeImpl(string name, int sides, ShapesEnum inShapeEnum, double width, double height) 
		: shapeName(name), noOfSides(sides), shapeEnum(inShapeEnum), shapeWidth(width),
		shapeHeight(height) {}
	
	string shapeName;
	ShapesEnum shapeEnum;

	int noOfSides;

	double shapeWidth;
	double shapeHeight;
};


Shape::Shape(std::string name, int sides, ShapesEnum shapeEnum, double width, double height) 
	: ShapeData(new ShapeImpl(name, sides, shapeEnum, width, height)) {};

Shape::~Shape() {
	delete ShapeData;
	ShapeData = nullptr;
}

std::string Shape::getName() const {
	return ShapeData->shapeName;
}

int Shape::getNumOfSides() const {
	return ShapeData->noOfSides;
}

ShapesEnum Shape::getShapeEnum() const {
	return ShapeData->shapeEnum;
}

double Shape::getShapeHeight() const
{
	return ShapeData->shapeHeight;
}

double Shape::getShapeWidth() const
{
	return ShapeData->shapeWidth;
}
