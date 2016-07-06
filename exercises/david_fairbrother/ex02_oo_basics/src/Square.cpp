
#include "Square.h"

#include <string>

struct Square::SquareImpl {

	SquareImpl(double length) : sideLength(length){}

	static const std::string shapeName;
	static const int sides = 4;

	double sideLength;

};

const std::string Square::SquareImpl::shapeName = "Square";


Square::Square(double sideLength) : Shape(squareData->shapeName, squareData->sides),
	squareData(new SquareImpl(sideLength)) {}

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