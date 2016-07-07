
#include "Square.h"
#include "shapeEnum.h"

#include <string>

struct Square::SquareImpl {

	SquareImpl() {}

	static const std::string shapeName;
	static const int sides = 4;

};

const std::string Square::SquareImpl::shapeName = "Square";


Square::Square(double sideLength, shapes shapeEnum) 
	: Shape(squareData->shapeName, squareData->sides, shapeEnum, sideLength),
	squareData(new SquareImpl()) {}

Square::~Square() {
	delete squareData;
	squareData = nullptr;
}

double Square::getArea() const{
	return getShapeWidth() * getShapeWidth();
}

double Square::getPerimeter() const{
	//Perimeter = 4 sides of length sideLength
	return  getShapeWidth() * 4;
}