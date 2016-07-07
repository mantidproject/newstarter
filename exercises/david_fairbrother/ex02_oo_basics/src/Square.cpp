
#include "Square.h"
#include "shapeEnum.h"

#include <string>

struct Square::SquareImpl {

	SquareImpl() {}

	static const std::string shapeName;
	static const int sides = 4;

	double sideLength;

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
	return squareData->sideLength * squareData->sideLength;
}

double Square::getPerimeter() const{
	//Perimeter = 4 sides of length sideLength
	return squareData->sideLength * 4;
}