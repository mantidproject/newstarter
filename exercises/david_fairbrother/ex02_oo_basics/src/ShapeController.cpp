
#include "ShapeController.h"

#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include <exception>
#include <string>

ShapeController::ShapeController() : ptrIsSet(false) {}

ShapeController::ShapeController(shapes newShape, double width, double height) : ptrIsSet(false) {
	setupShape(newShape, width, height);
}

ShapeController::ShapeController(const ShapeController &other) : ptrIsSet(false) {
	setupShape(other.getShapeEnum(), other.getShapeWidth(), other.getShapeHeight());
}

ShapeController::~ShapeController() {
	if (ptrIsSet) {
		delete shapePtr;
		shapePtr = nullptr;
	}
}

ShapeController& ShapeController::operator=(const ShapeController &other) {
	if (this != &other) {
		setupShape(other.getShapeEnum(), other.getShapeWidth(), other.getShapeHeight());
	}
	return *this;
}

void ShapeController::changeShape(shapes newShape, double width, double height) {
	setupShape(newShape, width, height);
}


std::string ShapeController::getShapeName() const {
	return shapePtr->getName();
}

shapes ShapeController::getShapeEnum() const {
	return shapePtr->getShapeEnum();
}


int ShapeController::getNoOfSides() const {
	return shapePtr->getNumOfSides();
}

double ShapeController::getShapeWidth() const {
	return shapePtr->getShapeWidth();
}

double ShapeController::getShapeHeight() const {
	return shapePtr->getShapeHeight();
}

double ShapeController::getShapeArea() const {
	return shapePtr->getArea();
}

double ShapeController::getShapePerimeter() const {
	return shapePtr->getPerimeter();
}

void ShapeController::setupShape(shapes newShape, double width, double height) {
	/*Create correct shape depending on parameter input and set dimensions		*
	*There is a better way of doing this than a switch case as this doesn't	*
	*scale very well, however I cannot remember it off the top of my head		*/

	if (ptrIsSet) {
		delete shapePtr;
		shapePtr = nullptr;
	}

	switch (newShape) {
	case SQUARE:
		shapePtr = new Square(width, newShape);
		break;
	case RECTANGLE:
		shapePtr = new Rectangle(height, width, newShape);
		break;
	case CIRCLE:
		shapePtr = new Circle(width, newShape);
		break;
	case TRIANGLE:
		shapePtr = new Triangle(width, height, newShape);
		break;
	default:
		throw std::domain_error("Shape parameter not valid");
	}

	ptrIsSet = true;
}