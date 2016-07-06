
#include "ShapeController.h"

#include "Square.h"
#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"

#include <exception>

ShapeController::ShapeController(shapes newShape, double width, double height, double radius) {
	//Create correct shape depending on parameter input and set dimensions 
	switch (newShape) {
	case SQUARE:
		shapePtr = new Square(width);
		break;
	case RECTANGLE:
		shapePtr = new Rectangle(height, width);
		break;
	case CIRCLE:
		shapePtr = new Circle(radius);
		break;
	case TRIANGLE:
		shapePtr = new Triangle(width, height);
		break;
	default:
		throw std::domain_error("Shape parameter not valid");
	}


}

ShapeController::~ShapeController() {
	delete shapePtr;
	shapePtr = nullptr;
}